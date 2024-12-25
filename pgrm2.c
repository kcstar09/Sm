<!DOCTYPE  html>

<head>

    <title>Time Table</title>
    
    <style>
        body {
            font-family: Arial, sans-serif;
        }

        table {
            width: 80%;
            margin: 20px auto;
            border-collapse: collapse;
        }

        th,
        td {
            border: 1px solid #ddd;
            padding: 8px;
            text-align: center;
        }

        th {
            background-color: #f4f4f4;
            color: #333;
        }

        tr:nth-child(even) {
            background-color: #f9f9f9;
        }

        tr:nth-child(odd) {
            background-color: #e6f7ff;
        }

        .lab-hour {
            background-color: #ffcccc;
        }

        .elective-hour {
            background-color: #ccffcc;
        }

        .highlight {
            font-weight: bold;
            color: #d63384;
        }

        tfoot {
            background-color: #e0e0e0;
            font-weight: bold;
        }
    </style>
</head>

<body>

    <h1 style="text-align: center;">Time Table</h1>

    <table>
        <thead>
            <tr>
                <th>Day/Time</th>
                <th>9:00 - 10:00</th>
                <th>10:00 - 11:00</th>
                <th>11:00 - 12:00</th>
                <th>12:00 - 1:00</th>
                <th>Lunch Break</th>
                <th>2:00 - 3:00</th>
                <th>3:00 - 4:00</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Monday</td>
                <td>Math</td>
                <td>English</td>
                <td class="lab-hour">Physics Lab</td>
                <td>Elective</td>
                <td rowspan="5" class="highlight">Break</td>
                <td class="elective-hour">Elective</td>
                <td>History</td>
            </tr>
            <tr>
                <td>Tuesday</td>
                <td class="elective-hour">Elective</td>
                <td>Biology</td>
                <td>Math</td>
                <td class="lab-hour">Chemistry Lab</td>
                <td>Geography</td>
                <td>PE</td>
            </tr>
            <tr>
                <td>Wednesday</td>
                <td>History</td>
                <td class="lab-hour">Computer Lab</td>
                <td>English</td>
                <td>Math</td>
                <td>Physics</td>
                <td class="elective-hour">Elective</td>
            </tr>
            <tr>
                <td>Thursday</td>
                <td>PE</td>
                <td>History</td>
                <td>Geography</td>
                <td class="elective-hour">Elective</td>
                <td>Biology</td>
                <td>Math</td>
            </tr>
            <tr>
                <td>Friday</td>
                <td class="lab-hour">Biology Lab</td>
                <td>Math</td>
                <td>English</td>
                <td>Physics</td>
                <td class="elective-hour">Elective</td>
                <td>Chemistry</td>
            </tr>
        </tbody>
        <tfoot>
            <tr>
                <td colspan="8">End of Timetable</td>
            </tr>
        </tfoot>
    </table>

</body>
</html>