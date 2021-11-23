 ## [![tests](https://github.com/ANGSD/mpileupreader/actions/workflows/tests.yml/badge.svg)](https://github.com/ANGSD/mpileupreader/actions/workflows/tests.yml) mpileupreader

# mpileupreader
Small example c++ code to parse mpileup files generated by samtools mpileup (not bcftools mpileup). Program accepts data piped into it like:

``` samtools mpileup your.bam |./mpileupreader ```

or as parameter

``` ./mpileupreader mpileup.txt.gz```

Porgram accepts BGZF or gz compressed files.

compile like

``` g++ mpileupreader.cpp -lz -O3 -o mpileupreader```

### Examples ###

```
git clone https://github.com/ANGSD/mpileupreader
cd mpileupreader
g++ mpileupreader.cpp -lz -O3 -o mpileupreader
gunzip -c mpil.gz 
1	14000074	N	4	gggG	@JFG	3	GGG	EFA
1	14000075	N	4	c$ccC	BJFG	4	CCC^>C	@A?<
1	14000076	N	3	ccC	JFI	4	CCCC	@B?B
1	14000077	N	3	ttT	GCI	4	TTTT	DDDD
1	14000078	N	3	ggG	DDH	4	GGGG	AFBF
1	14000079	N	3	ttT	FBD	4	TTTT	CCAC
1	14000080	N	3	ggG	ECH	4	GGGG	EF<F
1	14000081	N	3	ggG	EBJ	4	GGGG	>87=
1	14000082	N	3	ttT	ECF	4	TTTT	B=;A
1	14000083	N	3	ccC	??J	4	CCCC	=B2B

cat mpil.gz |./mpileupreder 
isterm: 0 argc: 1
chr: 1 pos: 14000074 ref: N
intid[0] idep: 4 mpil: gggG qscores: @JFG
intid[1] idep: 3 mpil: GGG qscores: EFA
chr: 1 pos: 14000075 ref: N
intid[0] idep: 4 mpil: c$ccC qscores: BJFG
intid[1] idep: 4 mpil: CCC^>C qscores: @A?<
chr: 1 pos: 14000076 ref: N
intid[0] idep: 3 mpil: ccC qscores: JFI
intid[1] idep: 4 mpil: CCCC qscores: @B?B
chr: 1 pos: 14000077 ref: N
intid[0] idep: 3 mpil: ttT qscores: GCI
intid[1] idep: 4 mpil: TTTT qscores: DDDD
chr: 1 pos: 14000078 ref: N
intid[0] idep: 3 mpil: ggG qscores: DDH
intid[1] idep: 4 mpil: GGGG qscores: AFBF
chr: 1 pos: 14000079 ref: N
intid[0] idep: 3 mpil: ttT qscores: FBD
intid[1] idep: 4 mpil: TTTT qscores: CCAC
chr: 1 pos: 14000080 ref: N
intid[0] idep: 3 mpil: ggG qscores: ECH
intid[1] idep: 4 mpil: GGGG qscores: EF<F
chr: 1 pos: 14000081 ref: N
intid[0] idep: 3 mpil: ggG qscores: EBJ
intid[1] idep: 4 mpil: GGGG qscores: >87=
chr: 1 pos: 14000082 ref: N
intid[0] idep: 3 mpil: ttT qscores: ECF
intid[1] idep: 4 mpil: TTTT qscores: B=;A
chr: 1 pos: 14000083 ref: N
intid[0] idep: 3 mpil: ccC qscores: ??J
intid[1] idep: 4 mpil: CCCC qscores: =B2B

```
