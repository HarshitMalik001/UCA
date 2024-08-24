
var arr = [2, 3, 6, 3];
var set1 = new Set()

set1.add(9);

// object

var obj1 = { name: "name1" };
var obj2 = Object.assign({}, obj1);

// Object.create





// let maxMarks = 500;
// var student = {
//     fName : "fName",
//     LName : "lname",
//     collage : "chitkara",
//     obtainMarks : 244,
//     checkResults : function(){
//         let percentage = (student.obtainMarks / maxMarks) * 100
//         if(percentage >= 40){
//             return "pass";
//         } else {
//             return "fail";
//         }
//     }
// }


// function student(fName, obtainMarks){
//     var std = {
//         fName : fName,
//         obtainMarks : obtainMarks,
//         checkResults : function(){
//             let percentage = (this.obtainMarks / maxMarks) * 100
//             if(percentage >= 40){
//                 return "pass";
//             } else {
//                 return "fail";
//             }
//         }
//     }
//     return std;
// }



// function student(fName, obtainMarks) {

//     this.fName = fName;
//     this.obtainMarks = obtainMarks;
//     this.checkResults = function () {
//         let percentage = (this.obtainMarks / maxMarks) * 100
//         if (percentage >= 40) {
//             return "pass";
//         } else {
//             return "fail";
//         }
//     }
// }

// var std1 = new student("dfg",434);




// class student {
//     constructor (fname, marks){
//         this.fname = fname;
//         this.marks = marks;
//     }


// }




function student(fname, marks){
    this.fname = fname;
    this.marks = marks;

    this.print = function(){
        console.log(this.fname);
    }
}
