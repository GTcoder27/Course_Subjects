package Main.service;


import Main.config.MapperConfig;
import Main.dto.QuestionDto;
import Main.entity.Question;
import Main.repository.QuestionRepository;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.ui.Model;

import java.util.List;
import java.util.stream.Collectors;

@Service
public class QuestionService {

    @Autowired
    QuestionRepository questionRepository;
    @Autowired
    ModelMapper modelMapper;


    public String addQuestion(List<QuestionDto> questions) {
        List<Question> new_questions = questions.stream()
                .map(q->modelMapper.map(q,Question.class))
                .collect(Collectors.toList());
        questionRepository.saveAll(new_questions);
        return "successfully added all questions";
    }

    public List<QuestionDto> getAllQuestions() {
        List<Question> questions = questionRepository.findAll();
        return questions.stream()
                .map(q->modelMapper.map(q,QuestionDto.class))
                .collect(Collectors.toList());
    }

//    public ResponseEntity<List<QuestionDto>> getQuestionsByDifficultyLevel(String difficultyLevel){
//        try{
//            return new ResponseEntity<>(questionRepository.getQuestionsByDifficultyLevel(difficultyLevel), HttpStatus.OK);
//        }
//        catch(Exception e){
//            e.printStackTrace();
//        }
//        return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
//    }


    public List<QuestionDto> getAllQuestionsByTopic(String topic) {
        List<Question> questions = questionRepository.getAllQuestionsByTopic(topic);
        return questions.stream()
                .map(q->modelMapper.map(q,QuestionDto.class))
                .collect(Collectors.toList());
    }

    public List<QuestionDto> getQuestionsByTopic(String topic, Integer noOfQuestions){
        List<Question> questions = questionRepository.getQuestionsByTopic(topic, noOfQuestions);
        return questions.stream()
                .map(q->modelMapper.map(q,QuestionDto.class))
                .collect(Collectors.toList());
    }


}
