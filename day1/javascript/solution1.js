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
rl.on('line', (line) => {
  processLine(line)
})

rl.on('close', () => {
  console.log(`totalSum: ${totalSum}`)
})

function processLine(line) {
  let firstNumber;
  let lastNumber;
  let sum = 0;

  for (let n of line) {
    if (Number.isInteger(parseInt(n))) {
      firstNumber = n
      break
    }
  }

  for (let i = line.length; i >= 0; i--) {
    if (Number.isInteger(parseInt(line[i]))) {
      lastNumber = line[i]
      break
    }
  }

  sum = parseInt(firstNumber + lastNumber)
  totalSum += sum
  console.log(`first: ${firstNumber}, last: ${lastNumber}, sum: ${sum}, totalSum: ${totalSum} line: ${line}`)

}

