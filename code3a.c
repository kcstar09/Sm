<!DOCTYPE html>

<head>
<title>Styled HTML Page | vtucode</title>
<link rel="stylesheet" href="style.css">
</head>

<body>

<h2>Main Heading</h2>
<h3>Subheading</h3>
<hr>
<p>This is a paragraph demonstrating the basic text styling applied by CSS.</p>

<div>
This is a styled <strong>div</strong> element with padding and a light border. Inside the div, we can also use
<span>span elements</span> that have their own styles, like this bold and orange text.
</div>

<p>Current time: <time>10:30 AM</time></p>

<img src="SECAB.jpeg" alt="Placeholder Image">

<p>Visit <a href="https://siet.secab.org/">SIET</a> to learn more about our services.</p>

<p class="highlight">This paragraph is highlighted with a yellow background.</p>
<p class="center">This text is centered using a class selector.</p>

<p id="special-paragraph">This is a special paragraph with unique styles applied through an ID selector.</p>

</body>

</html>












style.css



* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}

h2 {
    color: #2c3e50;
    font-size: 2em;
    margin-bottom: 10px;
}

h3 {
    color: #34495e;
    font-size: 1.5em;
    margin-bottom: 8px;
}

hr {
    border: 0;
    height: 2px;
    background-color: #e74c3c;
    margin: 20px 0;
}

p {
    font-family: 'Arial', sans-serif;
    line-height: 1.6;
    margin: 10px 0;
}

div {
    padding: 15px;
    border: 1px solid #bdc3c7;
    background-color: #ecf0f1;
}

span {
    color: #e67e22;
    font-weight: bold;
}

time::before {
    content: '⏰ ';
    color: #16a085;
}

img {
    margin-left: 15px;
    height: 300px;
    width: 400px;
    border-radius: 8px;
    box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
    max-width: 100%;
}

a {
    text-decoration: none;
    color: #ea0e4c;
}

a:hover {
    color: #6200ee;
    text-decoration: underline;
}

.highlight {
    background-color: yellow;
    padding: 3px;
}

.center {
    text-align: center;
}

#special-paragraph {
    font-size: 1.2em;
    color: #8e44ad;
    background-color: #f5f5f5;
    padding: 10px;
    border-left: 5px solid #8e44ad;
}

h2,
h3,
p {
    margin-left: 20px;
}