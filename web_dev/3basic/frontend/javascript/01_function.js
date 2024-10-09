var a = "harshit"

// function declaration
function fun1(b)
{
    console.log(b);
}


// function expression
var fun2 = function (b)
{
    console.log(b);
}


var fun3 = (b)=>
{
    console.log(b);
}


(b)=>
{
    console.log(b);
}



((b)=>
{
    console.log(b);
})()

fun1();
fun2();
fun3();