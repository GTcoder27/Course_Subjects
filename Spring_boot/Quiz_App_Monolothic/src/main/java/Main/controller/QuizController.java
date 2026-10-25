package Main.controller;


import Main.dto.CreateQuizInputDto;
import Main.dto.QuestionDto;
import Main.service.QuizService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("quiz")
public class QuizController {

    @Autowired
    QuizService quizService;

    @PostMapping("create")
    public String createQuiz(@RequestBody CreateQuizInputDto createQuizInputDto) {
        return quizService.createQuiz(createQuizInputDto.getTopic(),createQuizInputDto.getNoOfQuestions(),createQuizInputDto.getUniqueCode());
    }

    @GetMapping("get/{uniqueCode}")
    public List<QuestionDto> getQuiz(@PathVariable String uniqueCode){
        return quizService.getQuiz(uniqueCode);
    }






}
