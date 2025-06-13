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
    
    // Return JSON instead of HTML for AJAX
    header('Content-Type: application/json');
    echo json_encode($records);
    
} catch (PDOException $e) {
    echo json_encode(['error' => "Database error: " . $e->getMessage()]);
}
?>