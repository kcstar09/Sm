8)
Inside components, create Filter.js , TaskForm.js and TaskList.js files. Add commentMore actions
TaskForm.js
import React, { useState } from 'react';
function TaskForm({ addTask }) {
const [taskName, setTaskName] = useState('');
const [dueDate, setDueDate] = useState('');
const [description, setDescription] = useState('');
const handleSubmit = (e) => {
e.preventDefault();
if (taskName && dueDate) {
const newTask = {
id: Date.now(),
name: taskName,

dueDate: dueDate,
description,
completed: false,
};
addTask(newTask);
setTaskName('');
setDueDate('');
setDescription('');
}
};
return (
<form onSubmit={handleSubmit}>
<div>
<input
type="text"
placeholder="Task Name"
value={taskName}
onChange={(e) => setTaskName(e.target.value)}
/>
</div>
<div>
<input
type="date"
value={dueDate}
onChange={(e) => setDueDate(e.target.value)}
/>
</div>
<div>
<textarea
placeholder="Description (optional)"
value={description}
onChange={(e) => setDescription(e.target.value)}
/>
</div>
<button type="submit">Add Task</button>
</form>
);
}
export default TaskForm;  

Filter.js:
mport React from 'react';
function Filter({ setFilter }) {
return (
<div>

<button onClick={() => setFilter('all')}>All Tasks</button>
<button onClick={() => setFilter('completed')}>Completed Tasks</button>
<button onClick={() => setFilter('not-completed')}>Pending Tasks</button>
</div>
);
}
export default Filter;

TaskList.js:
import React from 'react';
function TaskList({ tasks, setTasks }) {
const toggleTaskCompletion = (taskId) => {
setTasks(
tasks.map((task) =>
task.id === taskId ? { ...task, completed: !task.completed } : task
)
);
};
const deleteTask = (taskId) => {
setTasks(tasks.filter((task) => task.id !== taskId));
};
return (
<div>
{tasks.length > 0 ? (
<ul>
{tasks.map((task) => (
<li key={task.id}>
<h3>{task.name}</h3>
<p>Due Date: {task.dueDate}</p>
{task.description && <p>Description: {task.description}</p>}
<p>Status: {task.completed ? 'Completed' : 'Not Completed'}</p>
<button onClick={() => toggleTaskCompletion(task.id)}>
{task.completed ? 'Mark as Not Completed' : 'Mark as Completed'}
</button>
<button onClick={() => deleteTask(task.id)}>Delete</button>
</li>
))}
</ul>
) : (
<p>No tasks available!</p>
)}
</div>
);
}
export default TaskList;

App.js
import React, { useState } from 'react';
import TaskForm from './components/TaskForm';
import TaskList from './components/TaskList';
import Filter from './components/Filter';
import './App.css';
function App() {
const [tasks, setTasks] = useState([]);
const [filter, setFilter] = useState('all');
const addTask = (task) => {
setTasks([...tasks, task]);
};
const handleFilterChange = (status) => {
setFilter(status);
};
const filteredTasks = tasks.filter((task) => {
if (filter === 'completed') return task.completed;
if (filter === 'not-completed') return !task.completed;
return true;
});
return (
<div className="App">
<h1>Task Reminder</h1>
<TaskForm addTask={addTask} />
<Filter setFilter={handleFilterChange} />
<TaskList tasks={filteredTasks} setTasks={setTasks} />
</div>
);
}
export default App;

App.css
body {
font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
margin: 0;
padding: 0;
Re
React Lab BCSL657B Page 37
Dept of CSE, SIET Vijayapura. 2025
background-color: #f0f4f8;
display: flex;
justify-content: center;
align-items: center;
min-height: 100vh;
}
.App {
width: 550px;
padding: 30px;
background-color: #ffffff;
border-radius: 12px;
box-shadow: 0 4px 16px rgba(0, 0, 0, 0.1);
transition: transform 0.3s ease, box-shadow 0.3s ease;
}
.App:hover {
transform: translateY(-5px);
box-shadow: 0 8px 24px rgba(0, 0, 0, 0.2);
}
h1 {
font-size: 2.2rem;
color: #333;
text-align: center;
margin-bottom: 10px;
margin-top: 0;
}
form {
display: flex;
flex-direction: column;
gap: 20px;
}
input,
textarea {
padding: 12px;
font-size: 1rem;
border: 1px solid #ccc;
border-radius: 8px;
transition: border-color 0.3s ease;
}
input:focus,
textarea:focus {
border-color: #4CAF50;
outline: none;
}
button {

background-color: #4CAF50;
color: white;
border: none;
padding: 12px;
font-size: 1rem;
border-radius: 8px;
cursor: pointer;
transition: background-color 0.3s ease, transform 0.3s ease;
}
button:hover {
background-color: #45a049;
}
button:active {
transform: scale(0.98);
}
textarea {
resize: vertical;
min-height: 120px;
}
input[type="date"] {
padding: 12px;
}
div {
display: flex;
flex-direction: column;
gap: 10px;
}
ul {
list-style-type: none;
padding: 0;
}
li {
background-color: #fafafa;
margin: 15px 0;
padding: 20px;
border-radius: 12px;
box-shadow: 0 4px 12px rgba(0, 0, 0, 0.1);
transition: transform 0.3s ease, box-shadow 0.3s ease;
}
li:hover {
transform: translateY(-5px);
box-shadow: 0 8px 20px rgba(0, 0, 0, 0.2);
}

h3 {
margin: 0;
font-size: 1.5rem;
color: #333;
font-weight: 600;
}
p {
margin: 5px 0;
color: #666;
}
button {
background-color: #007BFF;
color: white;
border: none;
padding: 8px 15px;
font-size: 1rem;
border-radius: 8px;
cursor: pointer;
transition: background-color 0.3s ease, transform 0.3s ease;
margin-right: 10px;
}
button:hover {
background-color: #0056b3;
}
button:active {
background-color: #003f8d;
}
button:last-child {
background-color: #e74c3c;
}
button:last-child:hover {
background-color: #c0392b;
}
button:last-child:active {
background-color: #7f1c1c;
}
.completed {
text-decoration: line-through;
color: #bbb;
}

div {
display: flex;
gap: 20px;
justify-content: center;
}
button {
background-color: #f1f1f1;
color: #333;
padding: 12px 18px;
font-size: 1rem;
border: 1px solid #ccc;
border-radius: 8px;
cursor: pointer;
transition: background-color 0.3s ease, transform 0.3s ease;
}
button:hover {
background-color: #ddd;
}
button:active {
transform: scale(0.98);
}
button:focus {
outline: none;
border-color: #007BFF;
}
