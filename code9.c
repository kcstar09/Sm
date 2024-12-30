<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>jQuery Append, Animate, and Color Change Demo</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
        body {
            font-family: Arial, sans-serif;
            line-height: 1.6;
            margin: 0;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 800px;
            margin: auto;
            background: white;
            padding: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0,0,0,0.1);
        }
        h1, h2 {
            color: #333;
        }
        .box {
            width: 100px;
            height: 100px;
            background-color: #3498db;
            margin: 20px 0;
        }
        button {
            padding: 10px 15px;
            background-color: #2ecc71;
            color: white;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            margin-right: 10px;
        }
        button:hover {
            background-color: #27ae60;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>jQuery Demonstration</h1>

        <h2>a. Append Content</h2>
        <p id="existingParagraph">This is an existing paragraph. </p>
        <ul id="existingList">
            <li>Existing item 1</li>
            <li>Existing item 2</li>
        </ul>
        <button id="appendButton">Append Content</button>

        <h2>b. Animate Element</h2>
        <div id="animateBox" class="box"></div>
        <button id="animateButton">Animate Box</button>

        <h2>c. Change Color of Animated Div</h2>
        <div id="colorBox" class="box"></div>
        <button id="colorAnimateButton">Animate and Change Color</button>
    </div>

    <script>
        $(document).ready(function() {
            // a. Append content
            $("#appendButton").click(function() {
                $("#existingParagraph").append("This content is appended.");
                $("#existingList").append("<li>Appended item</li>");
            });

            // b. Animate element
            $("#animateButton").click(function() {
                $("#animateBox").animate({
                    width: "200px",
                    height: "200px",
                    opacity: 0.5
                }, 1000);
            });

            // c. Animate and change color
            $("#colorAnimateButton").click(function() {
                $("#colorBox").animate({
                    width: "200px",
                    height: "200px"
                }, {
                    duration: 1000,
                    step: function(now, fx) {
                        if (fx.prop === "width") {
                            $(this).css("background-color", `rgb(${Math.round(now)}, 52, 219)`);
                        }
                    }
                });
            });
        });
    </script>
</body>
</html>