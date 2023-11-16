const gridContainer = document.querySelector(".grid");
const container = document.querySelector(".container");

const BLOCK_SIZE = 100;

let noOfBlocksInRow = 0;

function createGridItem(index) {
    const div = document.createElement("div");
    div.classList.add("grid-item");
    div.innerHTML = `${index}`;
    div.style.width = `${BLOCK_SIZE}px`;
    div.style.height = `${BLOCK_SIZE}px`;
    div.classList.add("block");
    div.dataset.position = index;
    // div.style.backgroundColor = randomColor();
    // div.style.opacity=0;
    return div;
}

function randomColor() {
    return `rgb(${Math.floor(Math.random() * 255)}, ${Math.floor(Math.random() * 255)}, ${Math.floor(Math.random() * 255)})`;
}

function createGrid() {
    let width = container.getBoundingClientRect().width;
    let height = container.getBoundingClientRect().height;
    let index = 0;

    while (width >= 0 || height >= 0) {
        const gridItem = createGridItem(index);
        gridContainer.appendChild(gridItem);
        index++;
        width -= BLOCK_SIZE;

        if (width <= 0 && height >= 0) {
            height -= BLOCK_SIZE;
            if (!noOfBlocksInRow) {
                noOfBlocksInRow = index;
                console.log("noOfBlocksInRow:",noOfBlocksInRow)
            }
            width = container.getBoundingClientRect().width;
        }
    }
}

function handleResize() {
    gridContainer.innerHTML = "";
    noOfBlocksInRow = 0;
    createGrid();
}

function findDimension(origin, noOfBlocksWithinRow) {
    const top = (origin - noOfBlocksWithinRow);
    const bottom = origin + noOfBlocksWithinRow;
    const left = origin-1;
    const right = origin+1;
    return [origin, top, bottom, left, right];
}
function handleMouseOver(e) {
    if (e.target.classList.contains("block")) {
        const dimension = findDimension(parseInt(e.target.dataset.position), noOfBlocksInRow);
        console.log(dimension);
        dimension.forEach(index => {
            const element = document.querySelector(`[data-position="${index}"]`);
            element && element.classList.add("animate");
        });
    }
}

function handleMouseOut(e) {
    if (e.target.classList.contains("block")) {
        const dimension = findDimension(parseInt(e.target.dataset.position), noOfBlocksInRow);
        dimension.forEach(index => {
            const element = document.querySelector(`[data-position="${index}"]`);
            element && element.classList.remove("animate");
        });
    }
}

window.addEventListener("resize", handleResize);
container.addEventListener("mouseover", handleMouseOver);
container.addEventListener("mouseout", handleMouseOut);
createGrid();
