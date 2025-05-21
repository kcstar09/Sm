ProfileCard.js:
import React, { useState } from 'react';
const ProfileCard = ({ name, bio, profilePicture }) => {
const [bgColor, setBgColor] = useState('#f0f0f0');
const handleMouseEnter = () => {
setBgColor('#d1c4e9');
};
const handleMouseLeave = () => {
setBgColor('#f0f0f0');
};

return (
<div
className="profile-card"
style={{ backgroundColor: bgColor }}
onMouseEnter={handleMouseEnter}
onMouseLeave={handleMouseLeave}
>
<img
src={profilePicture}
alt={`${name}'s profile`}
className="profile-picture"
/>
<div className="profile-info">
<h2 className="profile-name">{name}</h2>
<p className="profile-bio">{bio}</p>
</div>
</div>
);
};
export default ProfileCard;

 App.js
import React from 'react';
import ProfileCard from './ProfileCard';
import './App.css'
const App = () => {
return (
<div className="App">
<ProfileCard
name="vtucircle"
bio="vtucircle is the website which provides all the required VTU notes, syllabus, model papers,
previous
year papers of 2021 | 2022 scheme for BE students."
profilePicture="https://vtucircle.com/wp-content/uploads/2024/11/cropped-vtucircle_icon-1.png"
/>
</div>
);
};
export default App;

App.css
body {
font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
background-color: #f4f7fa;
display: flex;
justify-content: center;
align-items: center;
height: 100vh;
margin: 0;
}
.profile-card {
width: 320px;
padding: 30px;
border-radius: 15px;
text-align: center;
background-color: #ffffff;
box-shadow: 0 6px 12px rgba(0, 0, 0, 0.1);
transition: transform 0.3s ease, box-shadow 0.3s ease, background-color 0.3s ease;
cursor: pointer;
overflow: hidden;
margin: 20px;
}
.profile-card-container {
display: flex;
justify-content: center;
align-items: center;
height: 100vh;
width: 100%;
}
.profile-card:hover {
transform: translateY(-10px);
box-shadow: 0 12px 24px rgba(0, 0, 0, 0.2);
background-color: #f3f4f6;
}
.profile-picture {
width: 130px;
height: 130px;
border-radius: 50%;
object-fit: cover;
border: 4px solid #fff;
transition: transform 0.3s ease, box-shadow 0.3s ease;
}
.profile-card:hover .profile-picture {
transform: scale(1.1);

box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}
.profile-info {
font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
}
.profile-name {
font-size: 1.8rem;
font-weight: 600;
color: #333;
margin-bottom: 15px;
transition: color 0.3s ease;
}
.profile-card:hover .profile-name {
color: #5e35b1;
}
.profile-bio {
font-size: 1.1rem;
color: #555;
line-height: 1.5;
margin-bottom: 0;
transition: color 0.3s ease;
}
.profile-card:hover .profile-bio {
color: #444;
}
.profile-card-container {
display: flex;
justify-content: center;
align-items: center;
height: 100vh;
width: 100%;
background-color: #f4f7fa;
}
