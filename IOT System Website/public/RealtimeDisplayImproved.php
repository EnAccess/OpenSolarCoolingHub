<!DOCTYPE html>
<html>
<head>
    <title>Cold Room Monitor - Summary</title>
    <style>
        body {
            font-family: 'Segoe UI', sans-serif;
            background: linear-gradient(to right, #e3f2fd, #e8f5e9);
            padding: 30px;
            margin: 0;
        }

        h1, h2 {
            text-align: center;
            color: #00695c;
            margin-bottom: 20px;
        }

        .project-info {
            text-align: center;
            font-size: 16px;
            margin-bottom: 30px;
            color: #004d40;
        }

        .card-container {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 20px;
        }

        .sensor-card {
            background: linear-gradient(to bottom right, #ffffff, #f1fefc);
            border-radius: 12px;
            padding: 20px;
            width: 260px;
            box-shadow: 0 4px 10px rgba(0, 0, 0, 0.08);
            text-align: center;
            border-left: 6px solid #00acc1;
        }

        .sensor-card h3 {
            margin: 0 0 10px;
            font-size: 16px;
            color: #00796B;
        }

        .sensor-value {
            font-size: 24px;
            font-weight: bold;
            color: #004d40;
        }

        .timestamp {
            text-align: center;
            font-size: 14px;
            color: #607D8B;
            margin-top: 30px;
            font-style: italic;
        }

        .room-layout {
            display: grid;
            grid-template-columns: repeat(5, 1fr);
            gap: 10px;
            margin: 40px auto;
            max-width: 900px;
        }

        .sensor-box {
            background: #e3f2fd;
            border: 2px solid #90caf9;
            padding: 10px;
            border-radius: 8px;
            text-align: center;
            font-size: 12px;
            color: #0d47a1;
        }

        .refresh-indicator {
            position: fixed;
            top: 15px;
            right: 15px;
            padding: 8px 14px;
            background-color: #4CAF50;
            color: white;
            border-radius: 5px;
            opacity: 0;
            transition: opacity 0.5s;
            z-index: 999;
        }

        canvas {
            margin: 40px auto;
            display: block;
        }
    </style>
</head>
<body>
    <h1>FarmFreeze System</h1>
    

    <h2>Cold Room Latest Sensor Summary</h2>
    <div id="refresh-indicator" class="refresh-indicator">Refreshing...</div>
    <div class="card-container" id="summary-container"></div>

    <h2>Room Layout - Sensor Positions</h2>
    <div class="room-layout" id="room-layout"></div>

    <h2>Sensor Readings Over Time</h2>
    <canvas id="charts" width="900" height="600"></canvas>
        
    <div class="project-info">
        Designed and Developed By: Munakyalo Agrofresh Uganda Limited<br>
        and Enacces Foundation
    </div>

    <div id="last-updated" class="timestamp"></div>

    <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    <script>
        function showRefreshIndicator() {
            const indicator = document.getElementById('refresh-indicator');
            indicator.textContent = 'Refreshing...';
            indicator.style.opacity = '1';
            setTimeout(() => {
                indicator.style.opacity = '0';
            }, 2000);
        }

        function average(csv) {
            const nums = csv.split(',').map(Number);
            return (nums.reduce((a, b) => a + b, 0) / nums.length).toFixed(2);
        }

        function fetchData() {
            showRefreshIndicator();

            fetch('fetch_data.php')
                .then(response => response.json())
                .then(data => {
                    if (!data || data.length === 0) return;
                    const row = data[0];

                    const dhtHumidity = row.dht_humidity.split(',').map(Number);
                    const dhtTemp = row.dht_room_temp.split(',').map(Number);
                    const mlxObjTemp = row.mlx_object_temp.split(',').map(Number);
                    const mlxRoomTemp = row.mlx_room_temp.split(',').map(Number);

                    // Summary Cards
                    const readings = [
                        { title: 'Device ID', value: row.device_id },
                        { title: 'Avg DHT Humidity (%)', value: average(row.dht_humidity) },
                        { title: 'Avg DHT Room Temp (°C)', value: average(row.dht_room_temp) },
                        { title: 'Avg MLX Object Temp (°C)', value: average(row.mlx_object_temp) },
                        { title: 'Avg MLX Room Temp (°C)', value: average(row.mlx_room_temp) },
                        { title: 'Voltage (V)', value: row.voltage },
                        { title: 'Current (A)', value: row.current }
                    ];
                    document.getElementById('summary-container').innerHTML = readings.map(r => `
                        <div class="sensor-card">
                            <h3>${r.title}</h3>
                            <div class="sensor-value">${r.value}</div>
                        </div>
                    `).join('');

                    // Room Layout
                    let layout = '';
                    for (let i = 0; i < 10; i++) {
                        layout += `<div class='sensor-box'>
                            <strong>Sensor ${i + 1}</strong><br>
                            DHT Hum: ${dhtHumidity[i]}%<br>
                            DHT Temp: ${dhtTemp[i]}°C<br>
                            MLX Obj: ${mlxObjTemp[i]}°C<br>
                            MLX Room: ${mlxRoomTemp[i]}°C
                        </div>`;
                    }
                    document.getElementById('room-layout').innerHTML = layout;

                    // Charts
                    const ctx = document.getElementById('charts').getContext('2d');
                    new Chart(ctx, {
                        type: 'line',
                        data: {
                            labels: [...Array(10).keys()].map(i => 'Sensor ' + (i + 1)),
                            datasets: [
                                {
                                    label: 'DHT Humidity (%)',
                                    data: dhtHumidity,
                                    borderColor: '#2196f3',
                                    fill: false
                                },
                                {
                                    label: 'DHT Room Temp (°C)',
                                    data: dhtTemp,
                                    borderColor: '#4caf50',
                                    fill: false
                                },
                                {
                                    label: 'MLX Object Temp (°C)',
                                    data: mlxObjTemp,
                                    borderColor: '#f44336',
                                    fill: false
                                },
                                {
                                    label: 'MLX Room Temp (°C)',
                                    data: mlxRoomTemp,
                                    borderColor: '#ff9800',
                                    fill: false
                                }
                            ]
                        },
                        options: {
                            responsive: true,
                            plugins: {
                                legend: { position: 'bottom' },
                                title: { display: true, text: 'Sensor Data Over Time' }
                            }
                        }
                    });

                    // Timestamp
                    document.getElementById('last-updated').textContent = `Last updated: ${new Date(row.time_stamp).toLocaleString()}`;
                })
                .catch(err => console.error(err));
        }

        fetchData();
        setInterval(fetchData, 15000);
    </script>
</body>
</html>
