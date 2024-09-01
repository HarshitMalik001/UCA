// ---------------------------------------------------------------------------------------
function customPromiseExecuter()
{
    console.log("inside custom f1ex");
}

function customPromise(executerFuncArg){
    executerFuncArg();
    this.state = 'pending';
    let returnValue;
}


var promisec1 = new customPromise(customPromiseExecuter);


// ---------------------------------------------------------------------------------------


function customPromiseExecuter(resolve, reject)
{
    setTimeout(()=>{
        resolve({response : "value"});
        console.log("inside custom f1ex");
    },1000)
    
}

function customPromise(executerFuncArg){
    executerFuncArg(
        (responseArg) => {
            this.state = "fulfilled";
            console.log("inside Resolved value as ", responseArg);
        },
        (errorArg) => {
            this.state = "rejected";
            console.error("error with value as ", errorArg);
        }
    );
    this.state = 'pending';
    let returnValue;
}


var promisec1 = new customPromise(customPromiseExecuter);


//---------------------------------------------------------------------------------------


function customPromiseExecuter(resolve, reject)
{
    setTimeout(()=>{
        resolve({response : "value"});
        // console.log("inside custom f1ex");
    },1000)
    
}

function customPromise(executerFuncArg){
    this.state = 'pending';

    let successCallBack;
    let errorCallBack ;

    this.then = (arg1) =>{
        successCallBack = arg1;
       
    }

    this.catch = (arg2) =>{
        errorCallBack = arg2;
  
    }

    executerFuncArg(
        (responseArg) => {
            this.state = "fulfilled";
            // console.log("inside Resolved value as ", responseArg);
            successCallBack(responseArg);
        },
        (errorArg) => {
            this.state = "rejected";
            errorCallBack(errorArg);
            // console.error("error with value as ", errorArg);
        }
    );

}


var promisec1 = new customPromise(customPromiseExecuter);

promisec1.then((somevalue) => {
    console.log(somevalue);
})




// XMLH request