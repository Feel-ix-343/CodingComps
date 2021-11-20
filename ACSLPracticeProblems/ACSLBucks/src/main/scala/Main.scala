import io.StdIn.readLine
object Main extends App {
  val (message1, message2) = ("Enter your ticket: ", "Enter winning ticket: ")
  val input = readLine(message1).split(", ").map(Integer.parseInt).toList
  val numOfLines = 4
  val combinations = for (_ <- 1 to numOfLines) yield readLine(message2).split(", ").map(Integer.parseInt).toList
  def NumOfMatches(input: List[Int], ticket: List[Int]): (Int, Int) = {
    val matches = (for (num <- input) yield ticket.contains(num)).count(_ == true)
    if (input.sum == ticket.sum) (matches, matches * 2) else (matches, matches)
  }
  def getOrderedMatches(input: List[Int], ticket: List[Int]): (Int, Int) = {
    var matches = 0
    for (i <- 3 to 5) for (x <- 0 to ticket.length - i) if (ticket.containsSlice(input.slice(x, x + i))) matches = i
    if (input.sum == ticket.sum) (matches, matches * 2) else (matches, matches)
  }
  for (tkt <- combinations) {
    input match {
      case x if x == tkt => println(10000)
      case x if NumOfMatches(x, tkt)._1 == 6 => println(1000)
      case x if getOrderedMatches(x, tkt)._1 != 0 => println(50 * getOrderedMatches(x, tkt)._2)
      case x if 2 < NumOfMatches(x, tkt)._1 && NumOfMatches(x, tkt)._1 < 6 => println(25 * NumOfMatches(x, tkt)._2)
      case x if NumOfMatches(x, tkt)._1 == 2 => println((NumOfMatches(x, tkt)._2 * 12.5).asInstanceOf[Int])
      case x if NumOfMatches(x, tkt)._1 == 1 => println(NumOfMatches(x, tkt)._2 * 10)
      case _ => println(0)
    }
  }
}

/* Input:
5, 2, 12, 22, 16, 38
8, 33, 19, 12, 40, 7
9, 7, 12, 22, 16, 40
1, 17, 19, 35, 25, 30
5, 2, 13, 21, 15, 39
*/