const board = document.querySelector('.board');
const startButton = document.querySelector('.btn-start');
const model = document.querySelector('.model');
const startGameModel = document.querySelector('.start-game');
const gameOverModel = document.querySelector('.game-over');
const restartButton = document.querySelector('.btn-restart');

const highScoreElement = document.querySelector('#high-score');
const scoreElement = document.querySelector('#score');
const timeElement = document.querySelector('#time');

// Read high score as a number and fallback to 0
let highScoreValue = Number(localStorage.getItem("highScore")) || 0;
let score = 0;
let time = `00-00`;

highScoreElement.innerText = highScoreValue;

const blockHight = 50;
const blockWidth = 50;

let interverId = null;
let timerIntervalId = null;

const cols = Math.floor(board.clientWidth / blockWidth);
const rows = Math.floor(board.clientHeight / blockHight);

let food = { x: Math.floor(Math.random() * rows), y: Math.floor(Math.random() * cols) };

const blocks = [];
let snake = [
  { x: 1, y: 3 },
  { x: 1, y: 4 },
  { x: 1, y: 5 }
];
let direction = "down";

for (let row = 0; row < rows; row++) {
  for (let col = 0; col < cols; col++) {
    const block = document.createElement('div');
    block.classList.add("block");
    board.appendChild(block);
    blocks[`${row}-${col}`] = block;
  }
}

function rander() {
  let head = null;
  if (blocks[`${food.x}-${food.y}`]) blocks[`${food.x}-${food.y}`].classList.add("food");

  if (direction == "left") {
    head = { x: snake[0].x, y: snake[0].y - 1 };
  } else if (direction == "right") {
    head = { x: snake[0].x, y: snake[0].y + 1 };
  } else if (direction == "down") {
    head = { x: snake[0].x + 1, y: snake[0].y };
  } else if (direction == "up") {
    head = { x: snake[0].x - 1, y: snake[0].y };
  }

  // wall collision
  if (head.x < 0 || head.x >= rows || head.y < 0 || head.y >= cols) {
    clearInterval(interverId);
    clearInterval(timerIntervalId);
    model.style.display = "flex";
    startGameModel.style.display = "none";
    gameOverModel.style.display = "flex";
    return;
  }

  // food logic
  if (head.x == food.x && head.y == food.y) {
    if (blocks[`${food.x}-${food.y}`]) blocks[`${food.x}-${food.y}`].classList.remove("food");
    food = { x: Math.floor(Math.random() * rows), y: Math.floor(Math.random() * cols) };
    if (blocks[`${food.x}-${food.y}`]) blocks[`${food.x}-${food.y}`].classList.add("food");
    snake.unshift(head);
    score += 10;
    scoreElement.innerText = score;

    // update high score (use numeric comparison) and update UI + storage
    if (score > highScoreValue) {
      highScoreValue = score;
      localStorage.setItem("highScore", String(highScoreValue));
      highScoreElement.innerText = highScoreValue;
    }
  }

  // move snake: clear previous fills, shift, then draw
  snake.forEach(sagment => {
    if (blocks[`${sagment.x}-${sagment.y}`]) blocks[`${sagment.x}-${sagment.y}`].classList.remove("fill");
  });
  snake.unshift(head);
  snake.pop();
  snake.forEach(sagment => {
    if (blocks[`${sagment.x}-${sagment.y}`]) blocks[`${sagment.x}-${sagment.y}`].classList.add("fill");
  });
}

startButton.addEventListener("click", () => {
  // clear any existing intervals so we don't double-run
  clearInterval(interverId);
  clearInterval(timerIntervalId);

  model.style.display = "none";
  interverId = setInterval(() => { rander(); }, 300);

  timerIntervalId = setInterval(() => {
    let [min, sec] = time.split("-").map(Number);
    if (isNaN(min)) min = 0;
    if (isNaN(sec)) sec = 0;
    if (sec === 59) { min += 1; sec = 0; } else { sec += 1; }
    time = `${String(min).padStart(2, "0")}-${String(sec).padStart(2, "0")}`;
    timeElement.innerText = time;
  }, 1000);
});

restartButton.addEventListener("click", restartGame);

function restartGame() {
  clearInterval(interverId);
  clearInterval(timerIntervalId);

  if (blocks[`${food.x}-${food.y}`]) blocks[`${food.x}-${food.y}`].classList.remove("food");
  snake.forEach(segment => {
    if (blocks[`${segment.x}-${segment.y}`]) blocks[`${segment.x}-${segment.y}`].classList.remove("fill");
  });

  score = 0;
  time = `00-00`;
  direction = 'down';
  scoreElement.innerText = score;
  timeElement.innerText = time;
  highScoreElement.innerText = highScoreValue;

  snake = [
    { x: 1, y: 3 },
    { x: 1, y: 4 },
    { x: 1, y: 5 }
  ];
  food = { x: Math.floor(Math.random() * rows), y: Math.floor(Math.random() * cols) };

  model.style.display = "none";
  interverId = setInterval(() => { rander(); }, 300);

  timerIntervalId = setInterval(() => {
    let [min, sec] = time.split("-").map(Number);
    if (isNaN(min)) min = 0;
    if (isNaN(sec)) sec = 0;
    if (sec === 59) { min += 1; sec = 0; } else { sec += 1; }
    time = `${String(min).padStart(2, "0")}-${String(sec).padStart(2, "0")}`;
    timeElement.innerText = time;
  }, 1000);
}

addEventListener("keydown", (event) => {
  if (event.key == "ArrowUp") { direction = "up"; }
  else if (event.key == "ArrowRight") { direction = "right"; }
  else if (event.key == "ArrowLeft") { direction = "left"; }
  else if (event.key == "ArrowDown") { direction = "down"; }
});
