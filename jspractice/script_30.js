var outer = document.querySelectorAll(".outer");
const observer_ = new IntersectionObserver(entries => {
   entries.forEach(entry => {
      console.log("entry");
      const intersecting = entry.isIntersecting;
      entry.target.style.backgroundColor = intersecting ? "red" : "aqua";
   });
},{ threshold: 1 });

outer.forEach(element => {
   observer_.observe(element);
});

function run(gen) {
   var it = gen();
   function handleNext(value) {
     var next = it.next(value);
     return handleResult(next);
   }
 
   function handleResult(next) {
     if (next.done) {
       return Promise.resolve(next.value);
     } else {
       return Promise.resolve(next.value)
         .then(handleNext)
         .catch(function handleErr(err) {
           return Promise.resolve(it.throw(err)).then(handleResult);
         });
     }
   }
   return handleNext();
 }
 
