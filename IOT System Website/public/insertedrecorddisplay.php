<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Database configuration
$host = 'fdb1029.awardspace.net:3306';
$dbname = '4316094_birds';
$username = '4316094_birds';
$password = 'CWsCxwzHpRLZ_J4';

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Fetch the latest 100 records
    $stmt = $pdo->query("SELECT * FROM ColdRoomMonitor ORDER BY time_stamp DESC LIMIT 100");
    $records = $stmt->fetchAll(PDO::FETCH_ASSOC);

    echo "<h2>Latest 100 Cold Room Monitor Records</h2>";
    echo "<table border='1' cellpadding='8' cellspacing='0'>";
    echo "<tr>
            <th>ID</th>
            <th>Device ID</th>
            <th>DHT Humidity</th>
            <th>DHT Room Temp</th>
            <th>MLX Object Temp</th>
            <th>MLX Room Temp</th>
            <th>Voltage</th>
            <th>Current</th>
            <th>Timestamp</th>
          </tr>";

    foreach ($records as $row) {
        echo "<tr>
                <td>{$row['id']}</td>
                <td>{$row['device_id']}</td>
                <td>{$row['dht_humidity']}</td>
                <td>{$row['dht_room_temp']}</td>
                <td>{$row['mlx_object_temp']}</td>
                <td>{$row['mlx_room_temp']}</td>
                <td>{$row['voltage']}</td>
                <td>{$row['current']}</td>
                <td>{$row['time_stamp']}</td>
              </tr>";
    }

    echo "</table>";
} catch (PDOException $e) {
    echo "Database error: " . $e->getMessage();
}
?>
