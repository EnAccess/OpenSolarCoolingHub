<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);


// Set timezone to Kampala, Uganda (Africa/Kampala)
date_default_timezone_set('Africa/Kampala');

// Database configuration
$host = 'fdb1029.awardspace.net';
$port = 3306;
$dbname = '4316094_birds';
$username = '4316094_birds';
$password = 'CWsCxwzHpRLZ_J4';


//$host = 'fdb1029.awardspace.net:3306';
//$dbname = '4316094_birds';
//$username = '4316094_birds';
//$password = 'CWsCxwzHpRLZ_J4';


// Create connection using mysqli
$db = new mysqli($host, $username, $password, $dbname, $port);

// Check connection
if ($db->connect_error) {
    die("Connection failed: " . $db->connect_error);
}

// Get data from GET parameters
$device_id = $_GET['D_id'];
$dht_humidity = $_GET['d_h'];
$dht_room_temp = $_GET['d_t'];
$mlx_Object_temp = $_GET['m_Ot'];
$mlx_room_temp = $_GET['m_rt'];
$voltage = $_GET['v'];
$current = $_GET['c'];

// Build SQL query
$sql = "INSERT INTO ColdRoomMonitor (
    device_id, 
    dht_humidity, 
    dht_room_temp, 
    mlx_Object_temp, 
    mlx_room_temp, 
    voltage, 
    current, 
    time_stamp
) VALUES (
    '".$db->real_escape_string($device_id)."', 
    '".$db->real_escape_string($dht_humidity)."', 
    '".$db->real_escape_string($dht_room_temp)."', 
    '".$db->real_escape_string($mlx_Object_temp)."', 
    '".$db->real_escape_string($mlx_room_temp)."', 
    '".$db->real_escape_string($voltage)."', 
    '".$db->real_escape_string($current)."', 
    '".date("Y-m-d H:i:s")."'
)";

// Execute query
if ($db->query($sql) === FALSE) {
    echo "Error: " . $sql . "<br>" . $db->error;
} else {
    echo "<br>";
    echo $db->insert_id;
}
?>
