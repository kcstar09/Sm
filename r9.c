9)
Inside components, create Home.js , About.js, Contact.js and Navbar.js files.Add commentMore actions
  Home.js
  import React from 'react';
const Home = () => {
return (
<div>
<h2>Home Page</h2>

<p>Welcome to the Home Page!</p>
</div>
);
};
export default Home

About.js:
import React from 'react';
const About = () => {
return (
<div>
<h2>About Page</h2>
<p>Learn more about us on the About Page!</p>
</div>
);
};
export default About;

Contact.js:
import React from 'react';
const Contact = () => {
return (
<div>
<h2>Contact Page</h2>
<p>Get in touch with us through the Contact Page!</p>
</div>
);
};
export default Contact;

Navbar.js:
import React from 'react';
import { NavLink } from 'react-router-dom';
const Navbar = () => {
return (
<nav>
<ul>
<li>
<NavLink
to="/"

className={({ isActive }) => (isActive ? 'active' : '')}
>
Home
</NavLink>
</li>
<li>
<NavLink
to="/about"
className={({ isActive }) => (isActive ? 'active' : '')}
>
About
</NavLink>
</li>
<li>
<NavLink
to="/contact"
className={({ isActive }) => (isActive ? 'active' : '')}
>
Contact
</NavLink>
</li>
</ul>
</nav>
);
};
export default Navbar;

App.js
  mport React from 'react';
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import Navbar from './components/Navbar';
import Home from './components/Home';
import About from './components/About';
import Contact from './components/Contact';
import './App.css'
const App = () => {
return (
<Router>
<div>
<Navbar />
<div style={{ padding: '20px' }}>
<Routes>
<Route path="/" element={<Home />} />
<Route path="/about" element={<About />} />
<Route path="/contact" element={<Contact />} />

</Routes>
</div>
</div>
</Router>
);
};
export default App;

App.css
  body {
font-family: Arial, sans-serif;
background-color: #f4f4f4;
margin: 0;
padding: 0;
}
div {
margin: 0 auto;
max-width: 960px;
padding: 20px;
}
h2 {
color: #333;
padding-bottom: 20px;
}
nav {
background-color: #333;
padding: 10px;
border-radius: 5px;
margin-bottom: 20px;
}
ul {
list-style: none;
display: flex;
gap: 15px;
justify-content: center;
margin: 0;
padding: 0;
}
li {
display: inline;
}

a {
text-decoration: none;
color: white;
padding: 8px 16px;
border-radius: 4px;
}
a:hover {
background-color: #444;
}
a.active {
background-color: #1e90ff;
color: white;
font-weight: bold;
}
p {
color: #555;
font-size: 1.1rem;
line-height: 1.6;
}

(index.js
  import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
const rootElement = document.getElementById('root');
const root = ReactDOM.createRoot(rootElement);
root.render(<App />);
