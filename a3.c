 App.js
import React, { useState } from 'react';
import './App.css';
function App() {
const [counter, setCounter] = useState(0);
const [step, setStep] = useState(1);
const minValue = 0;
const handleIncrement = () => {
setCounter(prevCounter => prevCounter + step);
};
const handleDecrement = () => {
if (counter - step >= minValue) {
setCounter(prevCounter => prevCounter - step);
}
};
const handleReset = () => {
setCounter(0);
};
const handleStepChange = (event) => {
setStep(Number(event.target.value));
};
return (
<div style={{ textAlign: 'center', marginTop: '50px' }}>
<h1>Counter Application</h1>
<div style={{ fontSize: '48px', margin: '20px' }}>
<span>{counter}</span>
</div>
<div>
<button onClick={handleIncrement}>Increase by {step}</button>
<button onClick={handleDecrement}>Decrease by {step}</button>
<button onClick={handleReset}>Reset</button>
</div>
<div style={{ marginTop: '20px' }}>
<label>
Set Increment/Decrement Step:
<input
type="number"
value={step}
onChange={handleStepChange}
min="1"
style={{ marginLeft: '10px' }}
/>
</label>
</div>
</div>
);
}
export default App;

App.css
.App {
text-align: center;
}
button {
margin: 10px;
padding: 10px;
font-size: 16px;
cursor: pointer;
}
input {
padding: 5px;
font-size: 16px;
}
