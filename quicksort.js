/** @param {Number[]} arr */
module.exports = function QuickSort (arr, left, right) {
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
    let value = arr[pivot];
	let index = left;
    for (let i = left; i < right; i++) {
        if (arr[i] < value) {
            Swap(arr, i, index);
            index++;
        }
    }
    Swap(arr, right, index);
    return index;
}
function Swap (arr, i, j) {
    let tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}