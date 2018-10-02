#ifndef _TOKENSET_H
#define _TOKENSET_H

#include <vector>
#include <string>
#include <string.h>
#include <time.h>

namespace Mastermind
{

class TokenSet {
private:
	static constexpr char emptyToken = ' ';

	static constexpr size_t defaultNumTokens = 4;

	std::string tokenColors;  // TODO: duplicated in every TokenSet

	std::string tokens;

public:
	TokenSet(size_t numTokens = defaultNumTokens):
	tokenColors("RGBYOM"),
	tokens(numTokens, emptyToken)
    {
	}

	void clear()
	{
		tokens = std::string(tokens.length(), emptyToken);
	}

	void set(const std::string &newTokens)
	{
		tokens = newTokens;
	}

	TokenMatches match(const TokenSet &target) const
	{
		uint8_t fullMatches = 0;
		uint8_t colorMatches = 0;
        std::vector<uint8_t> targetColorCounters;
        std::vector<uint8_t> myColorCounters;

        targetColorCounters.resize(tokenColors.length(), 0);
        myColorCounters.resize(tokenColors.length(), 0);

		for (size_t i = 0;
				    i < std::min(tokens.length(), target.tokens.length());  // TODO defensive: replace with assert?
				    i++) {
			const char myColor = tokens[i];
			const char targetColor = target.tokens[i];

			if (tokenColors.find(myColor) == std::string::npos ||    // TODO defensive: replace with assert?
				tokenColors.find(targetColor) == std::string::npos) {
				continue;
			}

			if (myColor == targetColor){
				fullMatches++;
			} else {
		        targetColorCounters[tokenColors.find(targetColor)]++;
		        myColorCounters[tokenColors.find(myColor)]++;
			}
		}

		for(size_t i = 0; i < targetColorCounters.size(); i++){
			colorMatches += std::min(targetColorCounters[i], myColorCounters[i]);
		}

		return TokenMatches(fullMatches, colorMatches);
	}

	void random()
	{
		const size_t maxColors = tokenColors.size();
		for (auto &c : tokens){
			c = tokenColors.c_str()[rand()%maxColors];
		}
	}

	void paint() const
	{
		printf("%s\n", tokens.c_str());
	}
};

}
#endif
