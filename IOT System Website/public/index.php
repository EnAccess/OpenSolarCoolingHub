<?php
// Basic PHP configuration
ini_set('display_errors', 1);
error_reporting(E_ALL);

// Define any constants or initial variables
define('SITE_NAME', 'Munakyalo Agrofresh Cold Roomm Monitoring');

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo SITE_NAME; ?></title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            line-height: 1.6;
        }
        .container {
            max-width: 800px;
            margin: 0 auto;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Welcome to <?php echo SITE_NAME; ?></h1>
        <p>This is a basic PHP index page.</p>
        <p>Current server time: <?php echo date('Y-m-d H:i:s'); ?></p>
    </div>
</body>
</html>