package ACSLble
object Main extends App{
  def isVowel(c: Char): Int = c match {
    case ' ' => 3
    case 'E' => 2
    case _ => "AEIOU".count(c == _) // 0 if consonant, 1 if vowel
  }
  def changeY(s: String): String = {
    var out = s
    for (i <- 0 until s.length if s(i) == 'Y') yield {
      if (i != 0 && (s(i + 1) == ' ' && isVowel(s(i - 1)) == 0 || isVowel(s(i - 1)) == 0 && isVowel(s(i + 1)) == 0))
        out = out.replaceFirst("Y", "A")
      else out = out.replaceFirst("Y", "B")
    }
    out
  }
  def calcPairs(s: String): Int = List("IO","AO","EO","IA","II","UA","UE").map(p => s.sliding(2).count(_ == p)).sum
  def formsBlock(x: IndexedSeq[Int]): Boolean = {
    if (x(1) == 2) x(2) == 0 || x(2) == 3 && x(0) == 1
    else if (x(2) == 2) x(1) == 0
    else x(1) != x(2) && x(1) != 3
  }

  val inputs = for (i <- 1 to 5) yield changeY(scala.io.StdIn.readLine + " ")
  for (str <- inputs) {
    val firstLettersVal = if (formsBlock(IndexedSeq(' ', str(0), str(1)).map(isVowel))) 1 else 0
    var ACSLbleVal = firstLettersVal + str.sliding(3).map(_.map(isVowel)).count(formsBlock)
    ACSLbleVal += calcPairs(str)
    println(ACSLbleVal)
  }
}
