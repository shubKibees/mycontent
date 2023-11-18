November 6, 2023 Shubham Kumar

I had been using traditional methods for a long time to search for strings in an array and display them in the window. This involves using a linear search algorithm. However, recently I discovered a method that is much faster and more efficient than linear search. I found this method in a blog post by [ZhiHong Chua](https://dev.to/c6z3h).

**Source**: [Autocomplete Feature using Trie Data Structure](https://dev.to/c6z3h/autocomplete-feature-using-trie-data-structure-313g)

## Traditional Methods

The Traditional Method is a simple approach where we iterate over an array and use the string include method to determine if our string contains a prefix. If it does, we append it to a box that displays all the search results. If it doesn't contain the prefix, we don't include that string in the search result box.

%[https://codepen.io/shubKibees/pen/qBLoLez] 

**pros**

* ***Simplicity*:** The Traditional Method offers a straightforward and easy-to-understand approach for searching and displaying results.
    
* ***Readability*:** The code is easy to read and comprehend, making it accessible for developers of varying skill levels.
    
* ***Transparency*:** The logic is transparent, as it directly iterates through the array and checks for string inclusion, making it clear what the code is doing.
    

**Cons**

* ***Time Complexity*:** The time complexity of this method can be a drawback, especially for large datasets. The average word length (m) and the number of words in the array (n) result in a time complexity of O(m\*n). This means that the method's performance may degrade significantly when dealing with extensive lists of words.
    
* ***Space Complexity*:** The method's space complexity is also a concern, as it scales with the product of the average word length (m) and the number of words in the array (n), resulting in a space complexity of O(m\*n). This can lead to high memory consumption for large datasets.
    

## Trie Methods

%[https://codepen.io/shubKibees/pen/eYxgpPP] 

The Trie method is a somewhat complex approach where we create a tree data structure with nodes. Each node has two properties: map\_char&quot; which stores all the characters as keys and their corresponding values as another node, and endWord&quot; which is a boolean indicating whether the word ends at that node or not.

```javascript
class node{
   constructor(map_char=new Map(),endWord=false){
      this.map_char=map_char;
      this.endWord=endWord;
   }
}
```

We create another class called 'Tree' with three properties. The first property is 'root,' responsible for initializing the tree with the first node. The second property is 'storage,' used to store all the words to be inserted into the tree. The third property is 'word,' which stores the words to be displayed in the search results. We also automatically call the 'createTree' member function to insert words into the tree automatically.

```javascript
class tree {
   constructor(storage) {
     this.root = new node();
     this.words = []; 
     this.storage=storage;
     this.createTree();
   }
}

createTree(){
      for(let i=0;i<this.storage.length;i++){
         this.insert(this.storage[i]);
      }
      console.log("tree created again")
   }
```

The `insert()` member function is designed to insert a word into a tree data structure. This function iterates over each character in the input word, storing them one by one and creating new nodes in the tree as needed In summary, the `insert()` function traverses the tree character by character, creating new nodes as necessary, and marks the end of a word by setting the `endWord` property to `true` for the final character node. This effectively inserts the word into the tree data structure, allowing it to be later retrieved or searched for.

```javascript
insert(word) {
     let temp = this.root;
     for (let char of word) {
       if (!temp.map_char.has(char)) {
         temp.map_char.set(char, new node());
       }
       temp = temp.map_char.get(char);
     }
     temp.endWord = true;
   }
```

In summary, the ifPrefixExist() function searches for a prefix in the tree and, if found, returns an array of words with that prefix. If the prefix is not found, it returns an empty array.

```javascript
ifPrefixExist(prefix) {
     let temp = this.root;
     for (let char of prefix) {
       if (!temp.map_char.has(char)) {
         return [];
       }
       temp = temp.map_char.get(char);
     }
     this.words = []; 
     this.allWordwithPrefix(prefix, temp);
     return this.words;
   }
```

The allWordwithPrefix() function is designed to be automatically called when a prefix exists in the tree. It recursively fills an array called words with words that start with the specified prefix. Here's a step-by-step explanation of how it works:

```javascript
allWordwithPrefix(prefix, startNode, currentWord = '') {
     if (startNode.endWord) {
       this.words.push(prefix + currentWord);
     }
     for (let [key, value] of startNode.map_char) {
       this.allWordwithPrefix(prefix, value, currentWord + key);
     }
   }
```

1. allWordwithPrefix(prefix, startNode, currentWord = '') {: This function takes three parameters: prefix, startNode, and currentWord. prefix is the prefix for which we want to find matching words, startNode is the current node being examined in the tree, and currentWord is a string that accumulates the characters as the function traverses the tree.
    
2. if (startNode.endWord) {: This condition checks if the startNode represents the end of a word. If it does, it means that the path from the root to this node forms a complete word. In this case, the function appends the combination of the prefix and currentWord to the words array. This effectively adds a word that starts with the specified prefix to the results.
    
3. for (let \[key, value\] of [startNode.map](http://startNode.map)\_char) {: The function iterates over the characters and their corresponding child nodes in the map\_char property of the startNode. This loop allows the function to explore all possible paths in the tree that extend the current prefix.
    
4. this.allWordwithPrefix(prefix, value, currentWord + key);: Within the loop, the function calls itself recursively, passing the new value (child node) as the startNode. It also appends the current character (key) to the currentWord. This recursive call effectively continues the traversal of the tree, exploring all possible paths to find words that start with the specified prefix.
    

**Full code**

```javascript
var personDetail=["Ramlesh Singh","Ranjeet Singh","Anand K Singh","Ankur Goel","Vishesh Kumar Bhatia","Rishabh Kapoor","Manoj Gulati","Abhishek K Singh","Ashutosh Dubey".....]

class node{
   constructor(map_char=new Map(),endWord=false){
      this.map_char=map_char;
      this.endWord=endWord;
   }
}

class tree {
   constructor(storage) {
     this.root = new node();
     this.words = []; 
     this.storage=storage;
     this.createTree();
   }
 
   insert(word) {
     let temp = this.root;
     for (let char of word) {
       if (!temp.map_char.has(char)) {
         temp.map_char.set(char, new node());
       }
       temp = temp.map_char.get(char);
     }
     temp.endWord = true;
   }
 
   ifPrefixExist(prefix) {
     let temp = this.root;
     for (let char of prefix) {
       if (!temp.map_char.has(char)) {
         return false;
       }
       temp = temp.map_char.get(char);
     }
     this.words = []; 
     this.allWordwithPrefix(prefix, temp);
     return this.words;
   }
 
   allWordwithPrefix(prefix, startNode, currentWord = '') {
     if (startNode.endWord) {
       this.words.push(prefix + currentWord);
     }
     for (let [key, value] of startNode.map_char) {
       this.allWordwithPrefix(prefix, value, currentWord + key);
     }
   }
   createTree(){
      for(let i=0;i<this.storage.length;i++){
         this.insert(this.storage[i].toLowerCase());
      }
      console.log("tree created again")
   }
 }

var createSearchTree=new tree(personDetail); //creating the tree
const input_search=document.getElementById("inputSearch");
const search_box=document.getElementById("searchResult");
input_search.addEventListener("input",function(){
   var search_result=createSearchTree.ifPrefixExist(input_search.value);
   search_box.innerHTML="";
   if(search_result.length>0){
     search_result.forEach((txt)=>{
        search_box.appendChild(createLabel(txt));
     }) 
   }
   else{
      search_box.appendChild(createLabel("No Result Found"));
   }
})


var box=document.getElementById("searchResult");
box.addEventListener("click",function(e){
   var target=e.target;
   if(target.tagName=="P"){
      input_search.value=target.innerHTML;
      
   }
})


// input_search.addEventListener("input",function(){
//   search_box.innerHTML="";
//   personDetail.forEach((detail)=>{
//      if(detail.includes(input_search.value)){
//       search_box.appendChild(createLabel(txt));
//      }
//      else{
//       search_box.appendChild(createLabel("No Result Found"));
//      }
//   })
// })

function createLabel(text){
   var label=document.createElement("p");
   label.innerHTML=text;
   return label;
}
```