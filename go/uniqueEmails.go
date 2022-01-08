// https://leetcode.com/explore/interview/card/google/67/sql-2/3044/
package main

import (
	"fmt"
	"strings"
)

func numUniqueEmails(emails []string) int {
	uniqueEmails := map[string]int{}

	for _, email := range emails {
		// fmt.Println(i, email)

		emailComps := strings.Split(email, "@")

		localName := emailComps[0]
		domainName := emailComps[1]

		localNameComps := strings.Split(localName, "+")

		actualLocalName := localNameComps[0]

		actualLocalName = strings.ReplaceAll(actualLocalName, ".", "")

		uniqueEmails[actualLocalName+"@"+domainName] = 1
	}

	fmt.Println(uniqueEmails)

	return len(uniqueEmails)
}

func main() {
	// fmt.Println(numUniqueEmails([]string{"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"}))
	fmt.Println(numUniqueEmails([]string{"test.email+alex@leetcode.com", "test.email.leet+alex@code.com"}))
}
