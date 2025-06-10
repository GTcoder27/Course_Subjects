def bayes_inference(P_truth, P_event, P_lie, P_not_event):
    numerator = P_truth * P_event
    denominator = (P_truth * P_event) + (P_lie * P_not_event)
    return numerator / denominator

def main():
    print("Bayesian Inference Calculator")
    P_truth = float(input("Enter probability that the person tells the truth (0-1): "))
    P_event = float(input("Enter probability of the event happening (0-1): "))
    P_lie = 1 - P_truth
    P_not_event = 1 - P_event

    result = bayes_inference(P_truth, P_event, P_lie, P_not_event)
    print(f"\nThe probability that the event actually happened is: {result:.4f}")

if __name__ == "__main__":
    main()
