package main

import (
	"io"
	"os"
	"strings"
)

type rot13Reader struct {
	r io.Reader
}

func (r13 rot13Reader) Read(b []byte) (n int, err error) {
	n, e := r13.r.Read(b) //从io.Reader中将字符串读取到b中
	for i := 0; i < n; i++ {
		if b[i] >= 'a' && b[i] <= 'z' {
			b[i] = byte((int(b[i]-'a')+13)%26) + 'a'
		} else if b[i] >= 'a' && b[i] <= 'z' {
			b[i] = byte((int(b[i]-'A')+13)%26) + 'A'
		}
	}
	return n, e
}

func main() {
	s := strings.NewReader("Lbh penpxrq gur pbqr!")
	r := rot13Reader{s}
	io.Copy(os.Stdout, &r)
}
