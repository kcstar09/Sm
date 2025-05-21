BasicFigure.js:
import React from 'react';
const BasicFigure = ({ imageUrl, caption }) => {
return (
<div className="figure">
<img src={imageUrl} alt={caption} className="figure-image" />
<p className="figure-caption">{caption}</p>
</div>
);
};
export default BasicFigure;

FigureList.js
import React, { useState } from 'react';
import BasicFigure from './BasicFigure';
const FigureList = () => {
const [figures, setFigures] = useState([
{ imageUrl: 'https://picsum.photos/400', caption: 'Random Image 1' },
{ imageUrl: 'https://picsum.photos/400', caption: 'Random Image 2' },
{ imageUrl: 'https://picsum.photos/400', caption: 'Random Image 3' },
{ imageUrl: 'https://picsum.photos/400', caption: 'Random Image 4' },
]);
const addFigure = () => {
const newFigure = {
imageUrl: `https://picsum.photos/400?random=${figures.length + 1}`,
caption: `Random Image ${figures.length + 1}`,
};
setFigures([...figures, newFigure]);
};
const removeFigure = () => {
const updatedFigures = figures.slice(0, -1);
setFigures(updatedFigures);
};
return (
<div className="figure-list-container">
<div className='button-box'>
<button onClick={addFigure} className="action-button">Add Image</button>
<button onClick={removeFigure} className="action-button">Remove Image</button>
</div>
<div className="figure-list">
{figures.map((figure, index) => (
<BasicFigure key={index} imageUrl={figure.imageUrl} caption={figure.caption} />
))}
</div>
</div>
);
};
export default FigureList;

APP.js
import React from 'react';
import FigureList from './components/FigureList';
import './App.css';
const App = () => {
return (
<div className="app">
<h1>Dynamic Image Gallery</h1>
<FigureList />
</div>
);
};
export default App;

App.css
*{
padding: 0;
margin: 0;
box-sizing: border-box;
}
h1 {
background: #000;
color: #fff;
padding: 10px;
text-align: center;
}
.figure-list-container {
display: flex;
flex-direction: column;
align-items: center;
margin: 20px;
}
.button-box {
display: block;
text-align: center;
padding: 10px;
margin-bottom: 20px;
}
.action-button {
padding: 10px 20px;
margin: 10px;
background-color: #4CAF50;
color: white;
border: none;
border-radius: 5px;
cursor: pointer;
font-size: 16px;
transition: background-color 0.3s ease;
}
.action-button:hover {
background-color: #45a049;
}
.figure-list {
display: flex;
flex-wrap: wrap;
justify-content: center;
gap: 15px;
}
.figure-list img {
max-width: 200px;
max-height: 200px;
border: 2px solid #ccc;
border-radius: 8px;
}
figure {
display: flex;
flex-direction: column;
align-items: center;
}
figcaption {
margin-top: 8px;
font-size: 14px;
color: #555;
}
.figure {
display: flex;
flex-direction: column;
align-items: center;
border: 2px solid #ddd;
border-radius: 8px;
padding: 10px;
box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
transition: transform 0.2s ease, box-shadow 0.2s ease;
}
.figure:hover {
transform: translateY(-5px);
box-shadow: 0 6px 12px rgba(0, 0, 0, 0.2);
}
.figure-image {
max-width: 200px;
max-height: 200px;
border-radius: 8px;
object-fit: cover;
}
.figure-caption {
margin-top: 10px;
font-size: 14px;
color: #555;
text-align: center;
}
