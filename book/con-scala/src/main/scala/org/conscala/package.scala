package org

package object conscala {
  def log(msg: String): Unit =
    println(s"${Thread.currentThread.getName}: $msg")
}
