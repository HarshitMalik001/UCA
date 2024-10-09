// chaining + this = promise

var prm1 = new Promise(function (resolve, reject){
    resolve("kkk");
})

prm1.then((abc)=>{
    console.log(abc);
}).then((abc)=>{
    console.log(abc);
}).then((abc)=>{
    console.log(abc);
})




// Promise is n object created using Promise() constructer function and have two properties 
//state and 
// value

// state- possible value-
// - pending
// - fulfilled
// - rejected


// value Possible value
// - undefined
// - return value or error

// ---------------------------------------------------------------------------


function promiseExecuter()
{
    setTimeout(()=>{
        console.log("pE");
    },10000)
}


var promise1 = new Promise(promiseExecuter);
var promise1 = new Promise();


// ------------------------------------------------------------------------------





function promiseExecuter(resolve, reject)
{
    setTimeout(()=>{
        resolve({responce: "value"});
        console.log("pE");
    },10000)
}


var promise1 = new Promise(promiseExecuter);




// -------------------------------------------------------------------------------
