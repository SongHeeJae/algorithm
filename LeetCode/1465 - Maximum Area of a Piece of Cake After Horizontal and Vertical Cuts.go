/*
가장 큰 너비와 높이를 구한 뒤, 직사각형의 넓이를 구해주면 되었습니다.
*/

func maxArea(h int, w int, horizontalCuts []int, verticalCuts []int) int {
    const MODULO = 1000000007
    return (findMax(h, horizontalCuts) % MODULO) * (findMax(w, verticalCuts) % MODULO) % MODULO
}

func findMax(l int, cuts []int) int {
    sort.Ints(cuts)
    
    mx := l - cuts[len(cuts) - 1]
    if mx < cuts[0] {
        mx = cuts[0]
    }
    
    for i := 1; i<len(cuts); i++ {
        if cur := cuts[i] - cuts[i - 1]; cur > mx {
            mx = cur
        }
    }
    
    return mx
}
