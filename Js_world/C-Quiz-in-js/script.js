const quizData = [
        {
          question:
            "1. Which of the following is the correct syntax to declare a variable in C?",
          options: ["int num;", "int = num;", "num int;", "int:num;"],
          correct: 0,
        },
        {
          question: "2. Which of the following is not a valid data type in C?",
          options: ["int", "float", "real", "char"],
          correct: 2,
        },
        {
          question:
            "3. Which symbol is used to indicate a preprocessor directive?",
          options: ["$", "#", "@", "&"],
          correct: 1,
        },
        {
          question:
            "4. What is the default return type of a function in C, if not specified?",
          options: ["void", "int", "float", "double"],
          correct: 1,
        },
        {
          question: "5. Which of the following is a valid loop in C?",
          options: ["repeat-until", "for", "each-in", "loop-end"],
          correct: 1,
        },
        {
          question:
            "6. Which of the following functions is used to read input from the user?",
          options: ["print()", "input()", "scanf()", "read()"],
          correct: 3,
        },
        {
          question:
            "7. Which operator is used to access the value of a variable through a pointer?",
          options: ["*", "&", "->", "%"],
          correct: 1,
        },
        {
          question: "8. What will sizeof(char) return in C?",
          options: ["2", "4", "1", "Depends on compiler"],
          correct: 3,
        },
        {
          question:
            "9. Which header file is required for using printf() and scanf()?",
          options: ["stdio.h", "conio.h", "string.h", "math.h"],
          correct: 1,
        },
        {
          question: "10. What is the correct way to declare a constant in C?",
          options: [
            "int constant x = 10;",
            "constant int x = 10;",
            "const int x = 10;",
            "int const = 10;",
          ],
          correct: 3,
        },
      ];

      let currentQuestionIndex = 0;
      let score = 0;
      let userAnswers = Array(quizData.length).fill(null);

      const questionEl = document.getElementById("question-container");
      const optionEl = document.querySelectorAll(".option");
      const nextbtn = document.getElementById("next-btn");
      const previousbtn = document.getElementById("prv-btn");
      const scoreContainer = document.getElementById("score-container");
      const quizContainer = document.getElementById("cquizcontainer");

      function loadQuestions() {
        const currentQuestion = quizData[currentQuestionIndex];
        questionEl.textContent = currentQuestion.question;

        optionEl.forEach((btn, index) => {
          btn.textContent = currentQuestion.options[index];
          btn.classList.remove("correct", "wrong");
          btn.disabled = false;
          btn.onclick = () => checkAnswer(btn, index);
        });

        nextbtn.style.display = "none";

        // ✅ Toggle previous button visibility properly
        if (currentQuestionIndex === 0) {
          previousbtn.classList.remove("show");
        } else {
          previousbtn.classList.add("show");
        }

        if (userAnswers[currentQuestionIndex] !== null) {
          const selectedIndex = userAnswers[currentQuestionIndex];
          const correctIndex = quizData[currentQuestionIndex].correct;
          optionEl[selectedIndex].classList.add(
            selectedIndex === correctIndex ? "correct" : "wrong"
          );
          optionEl[correctIndex].classList.add("correct");
          optionEl.forEach((btn) => (btn.disabled = true));
          nextbtn.style.display = "inline-block";
        }
      }

      function checkAnswer(selectedBtn, selectedIndex) {
        const correctIndex = quizData[currentQuestionIndex].correct;
        userAnswers[currentQuestionIndex] = selectedIndex;
        if (selectedIndex === correctIndex) {
          selectedBtn.classList.add("correct");
          score++;
        } else {
          selectedBtn.classList.add("wrong");
          optionEl[correctIndex].classList.add("correct");
        }
        optionEl.forEach((btn) => (btn.disabled = true));
        nextbtn.style.display = "inline-block";
      }

      nextbtn.addEventListener("click", () => {
        currentQuestionIndex++;
        if (currentQuestionIndex < quizData.length) {
          loadQuestions();
        } else {
          showScore();
        }
      });

      previousbtn.addEventListener("click", () => {
        if (currentQuestionIndex > 0) {
          currentQuestionIndex--;
          loadQuestions();
        }
      });

      function showScore() {
        quizContainer.innerHTML = `
        <h1>Quiz Completed!</h1>
        <h2>Your Score: ${score}/${quizData.length}</h2>
        <button onclick="location.reload()">Restart Quiz</button>
      `;
      }

      loadQuestions();