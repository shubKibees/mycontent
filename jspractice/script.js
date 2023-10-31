//understand promise
// function createNewPromise(x) {
//    return new Promise((resolve, reject) => {
//       if (x > 0) {
//          resolve(x);
//       } else {
//          reject("negative value");
//       }
//    });
// };

// const promise = createNewPromise(5);

// create a normar generator

// function* gen() {
//    for (let i of [1, 2, 3, 4, 5, 6]) {
//       yield i;
//    }
// }

// const it = gen();
// console.log(it.next().value);
// console.log(it.next());
// console.log(it.next());
// console.log(it.next());
// console.log(it.next());

// // her array is a iterater, which has a iterator, call by for loop to iterate over the object or arry

// function request() {
//    setTimeout(() => {
//       it1.next();
//    }, 5000);
// }

// function* gen1() {
//    const res = yield request();
//    console.log("continue");
// }

// const it1 = gen1();
// it1.next();


// function request_promise() {
//    return new Promise((resolve, reject) => {
//       setTimeout(() => {
//          resolve("data");
//          it.next();
//       }, 5000);
//    })
// }

// function* generator() {
//    const promise1 = request_promise();
//    const promise2 = request_promise();
//    console.log("hellow");

//    const data = yield promise1;
//    const data2 = yield promise2;
//    console.log("heooi");
//    const promise3 = yield request_promise();
// }

// const it = generator();

// it.next();



function* generatorFunction() {
    while (true) {
       yield Date.now();
    }
 }

 const generator = generatorFunction();

 function animateTextPath() {
    const path = document.getElementById("path");
    const textPath = document.querySelector("#animatedText textPath");
    const now = generator.next().value;
    const t = (Math.sin(now / 34) ** 0.5 - 8.5) * 200; // Scale the value for smoother animation

    // Calculate a new path for the text to follow
    const pathLength = path.getTotalLength();
    const offset = (t % pathLength).toFixed(2);

    textPath.setAttribute("startOffset", offset);
    textPath.innerHTML(now)
    requestAnimationFrame(animateTextPath);
 }

 // Start the animation
 animateTextPath();