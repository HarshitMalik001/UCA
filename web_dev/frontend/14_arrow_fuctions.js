// function declaration this point to the object whichis calling 
function fooN(){
    console.log("function", this);
}

// function expression this point to parent
var fooA = () => {
    console.log("function",this);
}




function abc(){
    this.simple = function()
    {
        function simplechild(){
            console.log(this);
        }
        simplechild();
        var arrchild = ()=>{
            console.log(this);
        }

        arrchild();
    }

    this.arr = ()=>
    {
        function simplechild(){
            console.log(this);
        }
        simplechild();
        var arrchild = ()=>{
            console.log(this);
        }

        arrchild();
    }
    
}


var obj1 = new abc();