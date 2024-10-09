

function simple()
{
    return {
        innerfunction(){
            console.log("hello");
        }
    }
}

simple().innerfunction();

function myconcat(stringi)
{
    this.stringi = stringi;

    this.concat = function(stri){
        this.stringi = this.stringi + stri;
        return this;
    }
}

var obj2 = new myconcat("hello");
