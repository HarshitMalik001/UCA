
function MyPromise(executerFuncArg)
{
    this.state = "Pending";
    let successCallBack = ()=>{};
    let errorCallBack =()=>{};

    this.then = (arg1) =>{
        successCallBack = arg1;
        return this;
    }

    this.catch = (arg2) =>{
        errorCallBack = arg2;
        return this;
    }

    executerFuncArg(
    (ResolveArg)=>{
        this.state = "Resolved";
        successCallBack(ResolveArg);
    }, 
    (RejectArg)=>{
        this.state = "Rejected";
        errorCallBack(RejectArg);
    });
}



function executerFuncArg(resolve, reject)
{
    setTimeout(()=>{
        console.log("Inside executioner");
        resolve({value: "execValue"});
    },1000 )
}


var prm1 = new MyPromise(executerFuncArg);

prm1.then((a)=>{
    console.log("called inside then ", a);
}).then((a)=>{
    console.log("called inside then ", a);
}).catch((b)=>{
    console.log("called inside catch ", b);
})