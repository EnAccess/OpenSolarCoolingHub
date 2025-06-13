<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Real-Time Cold Room Monitor</title>
    <style>
        table { border-collapse: collapse; width: 100%; }
        th, td { padding: 8px; text-align: left; border: 1px solid #ddd; }
        th { background-color: #f2f2f2; }
        
        /* Styles for refresh indicator */
        .refresh-indicator {
            position: fixed;
            top: 10px;
            right: 10px;
            padding: 8px 12px;
            background-color: #4CAF50;
            color: white;
            border-radius: 4px;
            opacity: 0;
            transition: opacity 0.5s;
            z-index: 1000;
        }
        
        .refreshing {
            background-color: #2196F3;
        }
        
        .last-updated {
            margin-top: 10px;
            font-style: italic;
            color: #666;
        }
    </style>
</head>
<body>
    <h2>Latest 100 Cold Room Monitor Records</h2>
    <div id="refresh-indicator" class="refresh-indicator">Refreshing data...</div>
    <div id="data-container">
        <!-- Initial data will be loaded here -->
        <?php include 'fetch_data.php'; ?>
    </div>
    <div id="last-updated" class="last-updated"></div>

    <script>
    function showRefreshIndicator() {
        const indicator = document.getElementById('refresh-indicator');
        indicator.textContent = 'Refreshing data...';
        indicator.style.opacity = '1';
        indicator.classList.add('refreshing');
        
        // Hide after 2 seconds
        setTimeout(() => {
            indicator.style.opacity = '0';
        }, 2000);
    }
    
    function updateLastUpdatedTime() {
        const now = new Date();
        document.getElementById('last-updated').textContent = 
            `Last updated: ${now.toLocaleTimeString()}`;
    }

    function fetchData() {
        showRefreshIndicator();
        
        fetch('fetch_data.php')
            .then(response => response.json())
            .then(data => {
                if (data.error) {
                    console.error(data.error);
                    return;
                }
                
                // Build HTML table from JSON data
                let html = '<table border="1" cellpadding="8" cellspacing="0">';
                html += '<tr>' +
                        '<th>ID</th>' +
                        '<th>Device ID</th>' +
                        '<th>DHT Humidity</th>' +
                        '<th>DHT Room Temp</th>' +
                        '<th>MLX Object Temp</th>' +
                        '<th>MLX Room Temp</th>' +
                        '<th>Voltage</th>' +
                        '<th>Current</th>' +
                        '<th>Timestamp</th>' +
                        '</tr>';
                
                data.forEach(row => {
                    html += `<tr>
                        <td>${row.id}</td>
                        <td>${row.device_id}</td>
                        <td>${row.dht_humidity}</td>
                        <td>${row.dht_room_temp}</td>
                        <td>${row.mlx_object_temp}</td>
                        <td>${row.mlx_room_temp}</td>
                        <td>${row.voltage}</td>
                        <td>${row.current}</td>
                        <td>${row.time_stamp}</td>
                    </tr>`;
                });
                
                html += '</table>';
                document.getElementById('data-container').innerHTML = html;
                updateLastUpdatedTime();
                
                // Change indicator to show success
                const indicator = document.getElementById('refresh-indicator');
                indicator.textContent = 'Data updated!';
                indicator.classList.remove('refreshing');
            })
            .catch(error => {
                console.error('Error fetching data:', error);
                // Change indicator to show error
                const indicator = document.getElementById('refresh-indicator');
                indicator.textContent = 'Update failed!';
                indicator.style.backgroundColor = '#f44336';
                indicator.classList.remove('refreshing');
            });
    }

    // Fetch data immediately when page loads
    fetchData();
    
    // Then fetch every 5 seconds
    setInterval(fetchData, 10000);
    </script>
</body>
</html>