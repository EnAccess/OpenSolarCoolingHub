<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

// Database configuration
$host = 'localhost:3306';
$dbname = 'uhrfkbmy_FarmFreeze';
$username = 'uhrfkbmy_farmfreezeadmin';
$password = 'farm@Freeze25';

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Sample data
    $device_id = 'CR002';
    $dht_humidity = 55.2;
    $dht_room_temp = 22.5;
    $mlx_Object_temp = 23.8;
    $mlx_room_temp = 21.7;
    $voltage = 3.7;
    $current = 1.2;
    $time_stamp = date('Y-m-d H:i:s');

    // Prepare & execute
    $stmt = $pdo->prepare("INSERT INTO ColdRoomMonitor 
        (device_id, dht_humidity, dht_room_temp, mlx_Object_temp, mlx_room_temp, voltage, current, time_stamp) 
        VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

    $stmt->execute([
        $device_id,
        $dht_humidity,
        $dht_room_temp,
        $mlx_Object_temp,
        $mlx_room_temp,
        $voltage,
        $current,
        $time_stamp
    ]);

    echo "Record inserted successfully.";
} catch (PDOException $e) {
    echo "Database error: " . $e->getMessage();
}
?>
