 App.js
import React, { useState } from 'react';
import './App.css';
const ToDoFunction = () => {
const [tasks, setTasks] = useState([]);
const [newTask, setNewTask] = useState('');
const addTask = () => {
if (newTask.trim()) {
setTasks([
...tasks,
{ id: Date.now(), text: newTask, completed: false },
]);
setNewTask('');
}
};
const deleteTask = (taskId) => {
setTasks(tasks.filter(task => task.id !== taskId));
};
const toggleTaskCompletion = (taskId) => {
setTasks(tasks.map(task =>
task.id === taskId
? { ...task, completed: !task.completed }
: task
));
};
return (
<div className="todo-container">
<h2 className="todo-header">To-Do List</h2>
<div className="todo-input-wrapper">
<input
type="text"
value={newTask}
onChange={(e) => setNewTask(e.target.value)}
placeholder="Add a new task..."
className="todo-input"
/>
<button className="add-task-button" onClick={addTask}>Add Task</button>
</div>
<ul className="todo-list">
{tasks.map((task) => (
<li
key={task.id}
className={`todo-item ${task.completed ? 'completed' : ''}`}
>
<span
className="task-text"
onClick={() => toggleTaskCompletion(task.id)}
>
{task.text}
</span>
<button
className="delete-button"
onClick={() => deleteTask(task.id)}
>
❌
</button>
</li>
))}
</ul>
</div>
);
};
export default ToDoFunction;

 App.css
.todo-container {
font-family: 'Arial', sans-serif;
max-width: 500px;
margin: 50px auto;
padding: 20px;
border: 1px solid #e0e0e0;
border-radius: 8px;
background-color: #f9f9f9;
box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
text-align: center;
}
.todo-header {
color: #4A90E2;
font-size: 2rem;
margin-bottom: 20px;
}
.todo-input-wrapper {
display: flex;
justify-content: center;
margin-bottom: 20px;
}
.todo-input {
width: 70%;
padding: 10px;
border-radius: 4px;
border: 1px solid #ccc;
font-size: 1rem;
outline: none;
}
.add-task-button {
padding: 10px 15px;
margin-left: 10px;
background-color: #4CAF50;
color: white;
border: none;
border-radius: 4px;
font-size: 1rem;
cursor: pointer;
transition: background-color 0.3s;
}
.add-task-button:hover {
background-color: #45a049;
}
.todo-list {
list-style-type: none;
padding-left: 0;
margin: 0;
}
.todo-item {
display: flex;
align-items: center;
justify-content: space-between;
background-color: #fff;
padding: 12px;
margin: 10px 0;
border-radius: 5px;
border: 1px solid #ddd;
box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
transition: transform 0.2s ease-in-out;
}
.todo-item:hover {
transform: scale(1.03);
}
.todo-item.completed {
background-color: #f1f1f1;
text-decoration: line-through;
color: #aaa;
}
.task-text {
cursor: pointer;
font-size: 1.1rem;
color: #333;
transition: color 0.3s;
}
.task-text:hover {
color: #4CAF50;
}
.delete-button {
background: none;
border: none;
font-size: 1.1rem;
color: #ff6347;
cursor: pointer;
transition: color 0.3s;
}
.delete-button:hover {
color: #ff4500;
}
