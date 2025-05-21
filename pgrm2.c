App.js,
import React from 'react';
import Header from './Header';
import Footer from './Footer';
import './App.css';
function App() {
const title = "Welcome to My React App";
const tagline = "Building great apps with React";
const copyright = "© 2025 MyApp, All Rights Reserved";
return (
<div className="App">
<Header title={title} />
<Footer tagline={tagline} copyright={copyright} />
</div>
);
}
export default App;

Header.js
import React from 'react';
function Header(props) {
return (
<header>
<h1>{props.title}</h1>
</header>
);
}
export default Header;

Footer.js
    import React from 'react';
function Footer(props) {
return (
<footer>
<p>{props.tagline}</p>
<p>{props.copyright}</p>
</footer>
);
}
export default Footer;

App.css
    .App {
text-align: center;
font-family: Arial, sans-serif;
}
header {
background-color: #282c34;
padding: 20px;
color: white;
}
footer {
background-color: #282c34;
padding: 10px;
color: white;
position: absolute;
bottom: 0;
width: 100%;
text-align: center;
}
