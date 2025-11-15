//Trafic light 


let a = "red";
let b = "yellow";
let c = "green";

let color=b;
    

if (color===a)
{
    console.log("stop..");
}
else if(color===b)
{
    console.log("go slow");
}
else if(color===c){
    console.log("go....");
}

//check for voting system

let age=10;

if(age>=18){
    console.log("you are elegible for voting");
}
else{
    console.log("you are not elegible for voting");
}


//popcorn rate

let popcornSize='xl';


if(popcornSize=='xl'){
    console.log("price is 250 ruppes only...");
}
else if(popcornSize=='l'){
    console.log("price is 200 ruppes only...");
}
else if(popcornSize=='m'){
    console.log("price is 100 ruppes only...");
}
else if(popcornSize=='s'){
    console.log("price is 50 ruppes only...");
}


//print day

let day=70;


switch(day)
{
    case 1:
        console.log("Monday");
        break;

    case 2:
        console.log("Tuesday");
        break;

    case 3:
        console.log("Wednesday");
        break;

    case 4:
        console.log("Thursday");
        break;

    case 5: 
        console.log("Friday");
        break;

    case 6:
        console.log("Saturday");
        break;
    case 7:
        console.log("Sunday");
        break;

    default: 
        console.log("wrong day!..")
}


let firstName = prompt("Enter your name :");
console.log(firstName);


console.log(a);

var a=10;