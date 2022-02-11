/** @param {Number[]} arr */
// module.exports = function QuickSort (arr, left, right) {
function QuickSort (arr, left, right) {
    let pivot;
    let index;
    if (left < right) {
        pivot = right;
        index = Partition(arr, pivot, left, right);
        QuickSort(arr, left, index - 1);
        QuickSort(arr, index + 1, right);
    }
    return arr;
}
function Partition (arr, pivot, left, right){
	let index = left;
    for (let i = left; i < right; i++) {
        // console.log("in:", arr, "i:", i, "index", index, "right:", right);
        if (arr[i] < arr[pivot]) {
            console.log("in:", arr, "i:", i, "index", index, "right:", right, "pivot:", pivot);
            Swap(arr, i, index);
            index++;
        }
    }
    Swap(arr, right, index);
    // console.log("partition:", arr);
    return index;
}
function Swap (arr, i, j) {
    let tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    console.log("swap:", arr, i, j);
}

// console.log(QuickSort([2,1,3,4,8,6,5], 0, 6));
console.log(QuickSort([5,4,6,2,1,3], 0, 5));