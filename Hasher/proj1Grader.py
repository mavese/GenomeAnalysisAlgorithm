import random
import subprocess
subprocess.call('rm -f main', shell = True)
points = 0
didCompile = subprocess.Popen('g++ *.cpp *.h -o main', stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell = True)
if didCompile.communicate()[1] != "":
	print 'The program did not compile :(\n**************************************\n**************************************'
else:
	print 'The program compiled!!\n**************************************\n**************************************'
	points += 25
	word = ''
	isValid = True
	for i in range(1,5):
		word += 'A'
		print 'Testing 1st line of {}'.format(word)
		runCommand = './main {} ~/Documents/TaMaterials/GenomeAnalysisAlgorithm/chr2L.fa > wordLength{}.txt'.format(i, i)
		subprocess.call(runCommand, shell = True)
		command1 = 'cat ../myWordLength{}.txt | grep {}'.format(i, word)
		firstLineOfMyDoc = subprocess.check_output(command1, shell = True)
		command2 = 'cat wordLength{}.txt | grep {}'.format(i, word)
		firstLineOfStudentDoc = subprocess.check_output(command2, shell = True)
		if firstLineOfMyDoc != firstLineOfStudentDoc:
			isValid = False
			print 'Test failed {} does not equal {}'.format(firstLineOfMyDoc, firstLineOfStudentDoc)
			print '\n**************************************'
			break
		print 'Test passed\n**************************************'
		if i == 4:
			points += 25
	print '**************************************'
	word = ''
	for i in range(1,5):
		rndInt = random.randint(0,3)
		if rndInt == 0:
			word += 'A'
		elif rndInt == 1:
			word += 'C'
		elif rndInt == 2:
			word += 'G'
		else:
			word += 'T'
		print 'Testing {}'.format(word)
		command1 = 'cat ../myWordLength{}.txt | grep {}'.format(i, word)
		lineOfMyDoc = subprocess.check_output(command1, shell = True)
		command2 = 'cat wordLength{}.txt | grep {}'.format(i, word)
		lineOfStudentDoc = subprocess.check_output(command2, shell = True)
		if lineOfMyDoc != lineOfStudentDoc:
			isValid = false
			print 'Test failed {} does not equal {}'.format(lineOfMyDoc, lineOfStudentDoc)
			print '\n**************************************'
			break
		print 'Test passed\n**************************************'
		if i == 4:
			points += 5
print '**************************************'
print 'Student recieved {} points for the automated grading portion'.format(points)