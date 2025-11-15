//for each
let arr = [1, 2, 3, 4, 5];
function great() {
    console.log("hello");
}
arr.forEach(great);
arr.forEach(great);
arr.forEach(great);
arr.forEach(great);

//map
let arr01 = [2, 4, 6, 8];

let newarr = arr.map((ele) => {
    return ele * ele;
});

//filter
let num=[1,2,3,4,5,6,7,8,9,10];

let ans= num.filter((ele)=>{
    return ele%2==0; //even
})

//every
// let num=[1,8,3,5,7,9];

// let ans=num.every((ele)=>{
//     return ele%2!=0;
// })

//some
//  let num=[1,3,5,7,9,2];

// let ans=num.some((ele)=>{
//     return ele%2==0;
// })

//reduce
// let arr=[1,5,6,8];

// let ans=arr.reduce((acc,ele)=>{
//     return acc+ele;
// })


//practice question
//check if all the numbers in our array are multiples of 10 or not

// let arr=[10,40];

// let ans=arr.every((ele)=>{
//     return ele%10==0;
// })


//create a functio to find the min number in an array

// let arr=[-5,2,3,4,5,6,7,10,25];

// let ans=arr.reduce((min,arr)=>{
//     if(min<arr)
//     {
//         return min;
//     }
//     else{
//         return arr;
//     }
// })

//default parameter value

// function multipication(ele01,ele02=8)
// {
//     return ele01*ele02;
// }


// console.log(multipication(50));

//spread

// let arr=[2,5,6,8,6,20,4,20,52,6,4,5,8,5,4,52];

// console.log(...arr);

//destructuring

// let names=['tonny','steve','finch','marsh'];

// let [winner, runnerup, secondRunnerUp, ...others]=names;


//destructuring in object

// let student={
//     name: "sharddha",
//     age:19,
//     classname: 9,
//     subjects:['math','english','sanskrit','science'],
//     username: "user@123",
//     passwoard: "abc"
// }
// let{classname:whichclass, passwoard}=student;