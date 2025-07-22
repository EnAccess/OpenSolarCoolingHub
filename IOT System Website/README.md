# Farmer Dashboard
- PHP 8.1+ required
- MySQL database schema: `database/db_schema.sql`
- REST API endpoints documented in `/api/v1`
- Uses Chart.js for produce preservation analytics

# Deploying the Website Locally Using XAMPP

# Download and Install XAMPP
Visit the official XAMPP website:
👉 https://www.apachefriends.org/index.html
Download XAMPP for Windows, Linux, or Mac depending on your OS.
Install XAMPP by following the setup instructions. Choose default settings unless you need a custom path.

# Launch XAMPP and Start Services
Open the XAMPP Control Panel.
Start these two services:
 Apache (for PHP server)
 MySQL (for the database)

# Set Up Your Project Folder
Navigate to the XAMPP installation directory:
Default for Windows: C:\xampp\htdocs
Default for Linux/Mac: /opt/lampp/htdocs
Copy the project folder IOT System Website into htdocs.
Rename it to a simple name, like iot_dashboard, for easier access.

# Import the SQL Database
Open your browser and go to:
http://localhost/phpmyadmin
Create a new database. For example:
Database name: coldroom_monitor
Click Import and select ColdRoomMonitor.sql from your project folder.
Click Go to import the tables and data.

# Configuration
Open your PHP files fetch_data.php, insertrecordGET.php
$mysqli = new mysqli("localhost", "root", "", "coldroom_monitor");
Ensure:
Host is localhost
User is root
Password is "" (empty by default in XAMPP)
DB name matches the one you imported (coldroom_monitor)


# Run the Website
In your browser, go to:
http://localhost/iot_dashboard/index.php
Replace iot_dashboard with your folder name.
You can now access pages like:
RealtimeDisplayImproved.php:
http://localhost/iot_dashboard/RealtimeDisplayImproved.php
