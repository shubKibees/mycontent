// var outer = document.querySelectorAll(".outer");
// const observer_ = new IntersectionObserver(entries => {
//    entries.forEach(entry => {
//       console.log("entry");
//       const intersecting = entry.isIntersecting;
//       entry.target.style.backgroundColor = intersecting ? "red" : "aqua";
//    });
// },{ threshold: 1 });

// outer.forEach(element => {
//    observer_.observe(element);
// });

// function run(gen) {
//    var it = gen();
//    function handleNext(value) {
//      var next = it.next(value);
//      return handleResult(next);
//    }

//    function handleResult(next) {
//      if (next.done) {
//        return Promise.resolve(next.value);
//      } else {
//        return Promise.resolve(next.value)
//          .then(handleNext)
//          .catch(function handleErr(err) {
//            return Promise.resolve(it.throw(err)).then(handleResult);
//          });
//      }
//    }
//    return handleNext();
//  }


function defaultPractice({
  title = "---------title",
  gallery: {
    image_location = "---------------image_location",
    image_alt = "----------image_alt",
    theee: { thiei = "-----------thiei" } = {}
  } = {},
  content = "------------content"
} = {}) {
  console.log(title);
  console.log(image_alt)
  console.log(thiei)
  console.log(content)
  console.log(image_location);
}


defaultPractice({ gallery: { image_location: "img/block", theee: { thiei: "hellow" } }, content: "lofreii" })


//understand iteration


var fibonachi = {
  [Symbol.iterator]() {
    var firstChoise = 1, secondChoise = 1;
    return {
      [Symbol.iterator]() {
        return this;
      },
      next() {
        var currentChoise = secondChoise;
        firstChoise = secondChoise;
        secondChoise = currentChoise + firstChoise;
        return { value: currentChoise, done: false }
      },
      return(v) {
        console.log("generator end")
        return { value: v, done: true }
      }
    };
  }
}

for (let i of fibonachi) {
  console.log(i);
}






// var allPossibleSubstring = {
//   [Symbol.iterator]() {
//     var index = this.string_.length;
//     var subst = this.string_;
//     var substtemp;
//     return {
//       [Symbol.iterator]() {
//         return this;
//       },
//       next() {
//         if (index <= 0) {
//           return { done: true };
//         }
//         substtemp = { value: subst.substring(0, index), done: false };
//         index--;
//         return substtemp;
//       },
//       return(v) {
//         console.log("generator end");
//         return { value: v, done: true };
//       }
//     };
//   },
//   string_: "thiihiih"
// };

// allPossibleSubstring.string_ = "shubham";

// var length = allPossibleSubstring.string_.length--;
// for (let i of allPossibleSubstring) {
//   if (length <= 0) break;
//   length--;
//   console.log(i);
// }



//object should have static case
//function should have generated all the result, function means(generation);