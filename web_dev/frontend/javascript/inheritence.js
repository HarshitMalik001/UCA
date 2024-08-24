// prototypical inheritance
// achived through prototype chains

// function student(name){
//     this.name = name;
// }

// var student1 = new student("sss");

// student.prototype.maxmark = 100;

// student1.maxmark;


// var student1_1 = Object.create(student1);

//arr.forEach(callback)

//arr.forEachCustom(callback)

// Array.prototype.forEachCustom = function(callbackFunction){
//     console.log(this);
//     for(let i = 0; i < this.length; i++){
//         callbackFunction(this[i])
//     }
// }



// Array.prototype.forMapCustom = function(callbackFunction){
//     var arr = [];
//     for(let i = 0; i < this.length; i++){
//         arr.push(callbackFunction(this[i]));
//     }
//     return arr;
// }

// var arr = [1, 2, 3, 4];
// arr.forMapCustom((val) => { return 3 * val})


class student1{
    static gg = "this is static"
    #first;
    second;
    constructor(f,s)
    {
        this.#first = f;
        this.second = s;
    }
}

var s = new student1('d','dd');

