class Multiselect {
  constructor(selectBoxInput,multiselectElement, checkboxesElement, cpcpInputElement, gemCpcpSelectElement) {
    this.selectBoxInput = selectBoxInput;
    this.multiselectElement = multiselectElement;
    this.checkboxesElement = checkboxesElement;
    this.cpcpInputElement = cpcpInputElement;
    this.gemCpcpSelectElement = gemCpcpSelectElement;
    this.upIcon = multiselectElement.querySelector(".fa-angle-up");
    this.downIcon = multiselectElement.querySelector(".fa-angle-down");
    this.isCheckboxesVisible = false;
    this.selectBoxInput.addEventListener("click", this.handleClickEvent.bind(this));
    document.body.addEventListener("click", this.handleClickOutsideEvent.bind(this));
    this.gemCpcpSelectElement.addEventListener("change", this.handleSelectChangeEvent.bind(this));
    modelNameInput.addEventListener("input", this.handleModelNameInputChange.bind(this));
  }

  handleClickEvent(event) {
    event.preventDefault();
    if (this.isCheckboxesVisible) {
      this.hideCheckboxes();
    } else {
      this.showCheckboxes();
    }
  }

  handleClickOutsideEvent(event) {
    if (!this.multiselectElement.contains(event.target)) {
      this.hideCheckboxes();
    }
  }

  handleSelectChangeEvent(event) {
    if (event.target.value === "CPCP") {
      this.cpcpInputElement.style.display = "flex";
    } else {
      this.cpcpInputElement.style.display = "none";
    }
  }

  handleModelNameInputChange(event) {
    const allLabels = this.checkboxesElement.querySelectorAll("label");

    allLabels.forEach((label) => {
      if (label.innerText.toLowerCase().includes(event.target.value.toLowerCase())) {
        label.style.display = "block";
      } else {
        label.style.display = "none";
      }
    });
  }

  showCheckboxes() {
    this.checkboxesElement.style.display = "block";
    this.upIcon.style.display = "none";
    this.downIcon.style.display = "block";

    this.isCheckboxesVisible = true;
  }

  hideCheckboxes() {
    this.checkboxesElement.style.display = "none";
    this.upIcon.style.display = "block";
    this.downIcon.style.display = "none";

    this.isCheckboxesVisible = false;
  }
}


//object created
const multiselect = new Multiselect(
  document.querySelector(".selectBox"),
  document.querySelector(".multiselect"),
  document.getElementById("checkboxes"),
  document.querySelector(".CPCP_input"),
  document.querySelector(".two_select")
);

//--------------------------------//
class InputRowManager {
  constructor(checkboxesElement, appendNewFieldElement, selectPossible = 3) {
    this.checkboxesElement = checkboxesElement;
    this.appendNewFieldElement = appendNewFieldElement;
    this.defaultSelectPossible=selectPossible;
    this.selectPossible = selectPossible;

    this.checkboxesElement.addEventListener("click", this.handleClickEventForCheckbox.bind(this));
  }
  handleClickEventForCheckbox(event) {
    const targetElement = event.target;

    if (targetElement.tagName === "INPUT" && targetElement.type === "checkbox") {
      if (targetElement.checked && this.selectPossible > 0) {
        this.selectPossible--;
        this.createInputRow(targetElement.id, targetElement.value);
      } else if (this.selectPossible > 0) {
        if (this.removeInputRow(targetElement.id)) {
          this.selectPossible++;
        }
      } else {
        if(targetElement.checked){
          alert(`You can't select more than ${this.defaultSelectPossible} models`);
        }
        targetElement.checked = false;
        if (this.removeInputRow(targetElement.id)) {
          this.selectPossible++;
        }
      }
    }
  }

  createInputRow(id, value) {
    const newRow = document.createElement("tr");

    const createInput = (placeholder, name) => {
      const td = document.createElement("td");
      const input = document.createElement("input");
      input.type = "text";
      input.className = "form-control";
      input.placeholder = placeholder;
      input.name = name;
      input.required = true;
      if (name === "Model Name") {
        input.value = value;
      }
      td.appendChild(input);
      newRow.appendChild(td);
    };

    createInput("Model Name", "Model Name");
    createInput("Quantity", "quantity");
    createInput("T1 Price", "t1_price");
    createInput("T2 Price", "t2_price");
    createInput("Customer Price", "customer_price");

    newRow.id = `row_${id}`;
    this.appendNewFieldElement.appendChild(newRow);
  }

  removeInputRow(id) {
    const rowToRemove = document.getElementById(`row_${id}`);
    if (rowToRemove) {
      this.appendNewFieldElement.removeChild(rowToRemove);
      return true;
    }
    return false;
  }
}
//object created
const inputRowManager = new InputRowManager(
  document.getElementById("checkboxes"),
  document.querySelector("#append_new_field")
);





