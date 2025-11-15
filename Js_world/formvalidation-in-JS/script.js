 function validForm()
        {
            const name=document.getElementById('name').value;
            const email=document.getElementById('email').value;
            const age=document.getElementById('age').value;

            clearError();

            const nameRagex=/^[A-Za-z]{2,}(?: [A-Za-z]+)*$/;
            if(!name.match(nameRagex))
            {
            alert("please enter only (name)");
            document.getElementById("name").classList.add("error");
            return false;
            }
            const emailRegex=/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
            if(!email.match(emailRegex))
            {
            alert("please enter only (email)");
            document.getElementById("email").classList.add("error");
            return false;
            }
            if(age<1 || isNaN(age))
            {
            alert("please enter only (age)");
            document.getElementById("age").classList.add("error");
            return false;
            }
            return true
        }

        function clearError()
        {
            let inputs=document.querySelectorAll("input");
            inputs.forEach(input => {
                input.classList.remove("error");
            });
        }
