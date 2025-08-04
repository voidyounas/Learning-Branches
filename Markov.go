package main

import (
	"fmt"
	"math/rand"
	"strings"
	"time"
)

func buildMarkovChain(words []string) map[string][]string {
	chain := make(map[string][]string)
	for i := 0; i < len(words)-1; i++ {
		key := words[i]
		next := words[i+1]
		chain[key] = append(chain[key], next)
	}
	return chain
}

func generateText(chain map[string][]string, start string, length int) string {
	rand.Seed(time.Now().UnixNano())
	result := []string{start}
	word := start

	for i := 0; i < length-1; i++ {
		options := chain[word]
		if len(options) == 0 {
			break
		}
		next := options[rand.Intn(len(options))]
		result = append(result, next)
		word = next
	}

	return strings.Join(result, " ")
}

func main() {
	text := "go is simple and powerful and fast and efficient and elegant"
	words := strings.Fields(text)
	chain := buildMarkovChain(words)

	start := words[rand.Intn(len(words))]
	output := generateText(chain, start, 15)
	fmt.Println(output)
}
