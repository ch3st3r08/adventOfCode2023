//advent of code day 1
import fs from 'node:fs'
import readLine from 'node:readline'

//get params from command line
const args = process.argv.slice(2)
const filename = args[0]

const fileStream = fs.createReadStream(filename)
const rl = readLine.createInterface({
  input: fileStream,
  crLfDelay: Infinity
})

let totalSum = 0;
const numbers = new Map(Object.entries({
  "one": 1,
  "two": 2,
  "three": 3,
  "four": 4,
  "five": 5,
  "six": 6,
  "seven": 7,
  "eight": 8,
  "nine": 9
}))

rl.on('line', (line) => {
  processLine(line)
})

rl.on('close', () => {
  console.log(`totalSum: ${totalSum}`)
})

function reverseString(str) {
  return str.split("").reverse().join("");
}

function processLine(line) {
  let firstNumber;
  let lastNumber;
  let posibleNumber = ""
  let sum = 0;
  let found = false

  for (let n of line) {
    if (found) break

    if (Number.isInteger(parseInt(n))) {
      firstNumber = n
      found = true
    }

    posibleNumber += n
    if (posibleNumber.length >= 3) {
      for (let key of numbers.keys()) {
        if (posibleNumber.indexOf(key) !== -1) {
          firstNumber = numbers.get(key)
          found = true
          break
        }
      }
    }
  }

  posibleNumber = ""
  found = false

  for (let i = line.length; i >= 0; i--) {
    if (found) break

    if (Number.isInteger(parseInt(line[i]))) {
      lastNumber = line[i]
      found = true
    }

    if (posibleNumber.length >= 3) {

      for (let key of numbers.keys()) {

        if (posibleNumber.indexOf(reverseString(key)) !== -1) {
          lastNumber = numbers.get(key)
          found = true
          break
        }
      }
    }
    posibleNumber += line[i]
  }

  sum = String(firstNumber).concat(lastNumber)
  totalSum += parseInt(sum)
  console.log(`first: ${firstNumber}, last: ${lastNumber}, sum: ${sum}, totalSum: ${totalSum} line: ${line}`)
}
