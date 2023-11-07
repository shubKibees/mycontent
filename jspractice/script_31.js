const person = {
  name: "John Doe",
  age: 42,
  nationality: "American"
};

const personProxy = new Proxy(person, {
   get: (obj, prop) => {
     if (!obj[prop]) {
       console.log(`Hmm.. this property doesn't seem to exist`);
     } else {
       console.log(`The value of ${prop} is ${obj[prop]}`);
     }
   },
   set: (obj, prop, value) => {
     if (prop === "age" && typeof value !== "number") {
       console.log(`Sorry, you can only pass numeric values for age.`);
     } else if (prop === "name" && value.length < 2) {
       console.log(`You need to provide a valid name.`);
     } else {
       console.log(`Changed ${prop} from ${obj[prop]} to ${value}.`);
       obj[prop] = value;
     }
     return true;
   }
 });

const inputForm = document.getElementById("inputForm");
const nameInput = document.getElementById("name");
const ageInput = document.getElementById("age");
const nameOutput = document.getElementById("nameOutput");
const ageOutput = document.getElementById("ageOutput");

inputForm.addEventListener("submit", function (event) {
  event.preventDefault();
  const name = nameInput.value;
  const age = parseInt(ageInput.value, 10);

  personProxy.name = name;
  personProxy.age = age;

  nameOutput.textContent = person.name;
  ageOutput.textContent = person.age;
  personProxy.name
});
