Inside components, create Form.js file
import React, { useState, useEffect, useCallback } from 'react';
import './Form.css';
const Form = () => {
const [formData, setFormData] = useState({
name: '',
email: '',
password: '',
});
const [errors, setErrors] = useState({
name: '',
email: '',
password: '',
});
const [showPassword, setShowPassword] = useState(false);
const [isFormValid, setIsFormValid] = useState(false);
const handleChange = (e) => {
const { name, value } = e.target;
setFormData((prevState) => ({
...prevState,
[name]: value.trim(),
}));
};
const validateForm = useCallback(() => {
let isValid = true;
const newErrors = { name: '', email: '', password: '' };
if (!formData.name) {
newErrors.name = 'Name is required.';
isValid = false;
}
const emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
if (!formData.email || !emailPattern.test(formData.email)) {
newErrors.email = 'Please enter a valid email address.';
isValid = false;
}
if (!formData.password) {
newErrors.password = 'Password is required.';
isValid = false;
} else if (formData.password.length < 6) {
newErrors.password = 'Password must be at least 6 characters long.';
isValid = false;
}
setErrors(newErrors);
setIsFormValid(isValid);
}, [formData]);
useEffect(() => {
validateForm();
}, [formData, validateForm]);
const handleSubmit = (e) => {
e.preventDefault();
if (isFormValid) {
console.log('Form Data:', formData);
setFormData({
name: '',
email: '',
password: '',
});
}
};
return (
<div className="form-container">
<h2 className="form-title">Registration Form</h2>
<form onSubmit={handleSubmit} className="form">
<div className="form-group">
<label htmlFor="name" className="form-label">Name</label>
<input
type="text"
id="name"
name="name"
value={formData.name}
onChange={handleChange}
className={`form-input ${errors.name ? 'error' : ''}`}
placeholder="Enter your name"
/>
{errors.name && <div className="error-message">{errors.name}</div>}
</div>
<div className="form-group">
<label htmlFor="email" className="form-label">Email</label>
<input
type="email"
id="email"
name="email"
value={formData.email}
onChange={handleChange}
className={`form-input ${errors.email ? 'error' : ''}`}
placeholder="Enter your email"
/>
{errors.email && <div className="error-message">{errors.email}</div>}
</div>
<div className="form-group">
<label htmlFor="password" className="form-label">Password</label>
<input
type={showPassword ? 'text' : 'password'}
id="password"
name="password"
value={formData.password}
onChange={handleChange}
className={`form-input ${errors.password ? 'error' : ''}`}
placeholder="Enter your password"
/>
{errors.password && <div className="error-message">{errors.password}</div>}
</div>
<div className="form-group password-toggle">
<label>
<input
type="checkbox"
checked={showPassword}
onChange={() => setShowPassword(!showPassword)}
/>
Show Password
</label>
</div>
<div className="form-group">
<button type="submit" className="form-submit" disabled={!isFormValid}>
Submit
</button>
</div>
</form>
</div>
);
};
export default Form;

App.js
import React from 'react';
import './App.css';
import Form from './components/Form';
function App() {
return (
<div className="App">
<Form />
</div>
);
}
export default App;

App.css
.form-container {
width: 100%;
max-width: 500px;
margin: 0 auto;
padding: 20px;
background-color: #f7f7f7;
border-radius: 8px;
box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
}
.form-title {
text-align: center;
font-size: 24px;
margin-bottom: 20px;
color: #333;
}
.form {
display: flex;
flex-direction: column;
}
.form-group {
margin-bottom: 15px;
}
.form-label {
font-size: 14px;
font-weight: 600;
color: #555;
}
.form-input {
width: 100%;
padding: 12px;
margin-top: 5px;
border: 1px solid #ddd;
border-radius: 4px;
font-size: 16px;
box-sizing: border-box;
}
.form-input.error {
border-color: red;
}
.error-message {
color: red;
font-size: 12px;
margin-top: 5px;
}
.password-toggle {
margin-bottom: 20px;
}
.form-submit {
padding: 12px;
background-color: #4CAF50;
color: white;
border: none;
border-radius: 4px;
font-size: 16px;
cursor: pointer;
transition: background-color 0.3s;
}
.form-submit:disabled {
background-color: #ccc;
cursor: not-allowed;
}
.form-submit:hover:not(:disabled) {
background-color: #45a049;
}
