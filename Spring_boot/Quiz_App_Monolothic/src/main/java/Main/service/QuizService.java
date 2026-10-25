package Main.service;


import Main.dto.QuestionDto;
import Main.dto.QuizDto;
import Main.entity.Question;
import Main.entity.Quiz;
import Main.repository.QuestionRepository;
import Main.repository.QuizRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

@Service
public class QuizService {

    @Autowired
    QuizRepository quizRepository;
    @Autowired
    QuestionService questionService;
    @Autowired
    ModelMapper modelMapper;

    public String createQuiz(String topic, Integer noOfQuestions, String uniqueCode){
        QuizDto quizDto = new QuizDto();
        quizDto.setUniqueCode(uniqueCode);
        List<QuestionDto> questions = questionService.getQuestionsByTopic(topic,noOfQuestions);
        if(questions.size()<=0){ return "no questions found";}
        quizDto.setQuestions(questions);

        Quiz new_quiz = modelMapper.map(quizDto,Quiz.class);
        quizRepository.save(new_quiz);
        return "You can access Quiz with Unique code = "+uniqueCode;
    }

    public List<QuestionDto> getQuiz(String uniqueCode){
        Quiz quiz = quizRepository.findByUniqueCode(uniqueCode);
        return quiz.getQuestions().stream()
                .map(q->modelMapper.map(q,QuestionDto.class))
                .collect(Collectors.toList());
    }


}
